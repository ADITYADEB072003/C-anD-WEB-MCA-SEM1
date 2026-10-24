
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#define TOTAL 5
#define OPTIONS 4
#define TIME_LIMIT 3
#define MARKS 10
#define INPUT_SIZE 128

typedef struct Result {
    int score;
    int correct;
    int wrong;
    int timedOut;
    int attempted;
    int completed;
    float percentage;
} Result;

/* Return values for timed input */
enum InputStatus {
    INPUT_ERROR = -1,
    INPUT_TIMEOUT = 0,
    INPUT_OK = 1,
    INPUT_TOO_LONG = 2
};

void displayquestion(int i, char question[][100],
                     char options[][OPTIONS][100]);

void showresult(Result result);

int readLineWithTimeout(char *buffer, size_t size, int seconds);

int parseAnswer(const char *input, int *answer);

int main(void) {
    char input[INPUT_SIZE];
    int answer;
    int status;

    char question[TOTAL][100] = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "What is the largest ocean on Earth?",
        "Who wrote the play 'Romeo and Juliet'?",
        "What is the chemical symbol for gold?"
    };

    char options[TOTAL][OPTIONS][100] = {
        {"Paris", "London", "Berlin", "Madrid"},
        {"Earth", "Mars", "Jupiter", "Saturn"},
        {"Atlantic Ocean", "Indian Ocean",
         "Arctic Ocean", "Pacific Ocean"},
        {"William Shakespeare", "Charles Dickens",
         "Mark Twain", "Jane Austen"},
        {"Au", "Ag", "Fe", "Hg"}
    };

    /* Answers are option numbers, not array indices. */
    int correctAnswers[TOTAL] = {1, 2, 4, 1, 1};

    char explanation[TOTAL][150] = {
        "Paris is the capital city of France.",
        "Mars appears red because of iron oxide on its surface.",
        "The Pacific Ocean is the largest ocean on Earth.",
        "William Shakespeare wrote Romeo and Juliet.",
        "Au comes from the Latin word Aurum, meaning gold."
    };

    Result result = {0};

    printf("Welcome to the Quiz!\n");
    printf("You will be asked %d questions.\n", TOTAL);
    printf("Enter an option number between 1 and %d.\n", OPTIONS);
    printf("You have %d seconds per question.\n\n", TIME_LIMIT);

    for (int i = 0; i < TOTAL; i++) {
        displayquestion(i, question, options);

        while (1) {
            printf("Your answer: ");
            fflush(stdout);

            status = readLineWithTimeout(
                input, sizeof(input), TIME_LIMIT
            );

            if (status == INPUT_TIMEOUT) {
                printf("\nTime's up!\n");
                printf("Correct answer: %s\n",
                       options[i][correctAnswers[i] - 1]);
                printf("Learning tip: %s\n\n", explanation[i]);

                result.wrong++;
                result.timedOut++;
                result.completed++;
                break;
            }

            if (status == INPUT_ERROR) {
                printf("\nInput ended or an input error occurred.\n");
                printf("The quiz will terminate.\n");
                goto finish;
            }

            if (status == INPUT_TOO_LONG) {
                printf("\nInput too long. Enter one option number.\n\n");
                continue;
            }

            if (!parseAnswer(input, &answer)) {
                printf("Invalid input! Enter a whole number "
                       "from 1 to %d.\n\n", OPTIONS);
                continue;
            }

            if (answer < 1 || answer > OPTIONS) {
                printf("Invalid option! Enter a number from "
                       "1 to %d.\n\n", OPTIONS);
                continue;
            }

            /* A valid answer has now been submitted. */
            result.attempted++;
            result.completed++;

            if (answer == correctAnswers[i]) {
                printf("Correct answer!\n\n");
                result.score += MARKS;
                result.correct++;
            } else {
                printf("Wrong answer!\n");
                printf("Correct answer: %s\n",
                       options[i][correctAnswers[i] - 1]);
                printf("Learning tip: %s\n\n", explanation[i]);
                result.wrong++;
            }

            break;
        }
    }

finish:
    if (result.completed > 0) {
        result.percentage =
            (float)result.score /
            (result.completed * MARKS) * 100.0f;
    } else {
        result.percentage = 0.0f;
    }

    showresult(result);

    return 0;
}

/*
 * Wait for a complete input line, but stop waiting when
 * the deadline expires. Uses POSIX APIs available on macOS/Linux.
 *
 * Returns:
 * INPUT_OK       - a line was read
 * INPUT_TIMEOUT - deadline expired
 * INPUT_ERROR   - EOF or read/select error
 * INPUT_TOO_LONG - input exceeded the buffer
 */
int readLineWithTimeout(char *buffer, size_t size, int seconds) {
    struct timespec start, now;
    size_t len = 0;
    int tooLong = 0;

    if (size < 2 || clock_gettime(CLOCK_MONOTONIC, &start) == -1) {
        return INPUT_ERROR;
    }

    while (1) {
        if (clock_gettime(CLOCK_MONOTONIC, &now) == -1) {
            return INPUT_ERROR;
        }

        double elapsed =
            (double)(now.tv_sec - start.tv_sec) +
            (double)(now.tv_nsec - start.tv_nsec) / 1e9;

        double remaining = seconds - elapsed;

        if (remaining <= 0.0) {
            if (isatty(STDIN_FILENO)) {
                tcflush(STDIN_FILENO, TCIFLUSH);
            }
            return INPUT_TIMEOUT;
        }

        struct timeval timeout;
        timeout.tv_sec = (long)remaining;
        timeout.tv_usec =
            (long)((remaining - timeout.tv_sec) * 1000000.0);

        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);

        int ready = select(STDIN_FILENO + 1, &readfds,
                           NULL, NULL, &timeout);

        if (ready == 0) {
            if (isatty(STDIN_FILENO)) {
                tcflush(STDIN_FILENO, TCIFLUSH);
            }
            return INPUT_TIMEOUT;
        }

        if (ready < 0) {
            if (errno == EINTR) {
                continue;
            }
            return INPUT_ERROR;
        }

        char ch;
        ssize_t bytes = read(STDIN_FILENO, &ch, 1);

        if (bytes == 0) {
            return INPUT_ERROR;
        }

        if (bytes < 0) {
            if (errno == EINTR) {
                continue;
            }
            return INPUT_ERROR;
        }

        /* A line is complete when Enter is pressed. */
        if (ch == '\n') {
            if (tooLong) {
                return INPUT_TOO_LONG;
            }

            buffer[len] = '\0';
            return INPUT_OK;
        }

        /* Ignore carriage returns from CRLF input. */
        if (ch == '\r') {
            continue;
        }

        if (len < size - 1) {
            buffer[len++] = ch;
        } else {
            tooLong = 1;
        }
    }
}

/* Accept only a complete integer, such as "2", not "2abc". */
int parseAnswer(const char *input, int *answer) {
    char *end;
    long value;

    while (*input == ' ' || *input == '\t') {
        input++;
    }

    if (*input == '\0') {
        return 0;
    }

    errno = 0;
    value = strtol(input, &end, 10);

    if (input == end || errno == ERANGE ||
        value < INT_MIN || value > INT_MAX) {
        return 0;
    }

    while (*end == ' ' || *end == '\t') {
        end++;
    }

    if (*end != '\0') {
        return 0;
    }

    *answer = (int)value;
    return 1;
}

void displayquestion(int i, char question[][100],
                     char options[][OPTIONS][100]) {
    printf("Question %d: %s\n", i + 1, question[i]);

    for (int j = 0; j < OPTIONS; j++) {
        printf("%d. %s\n", j + 1, options[i][j]);
    }
}

void showresult(Result result) {
    printf("\n========== QUIZ RESULTS ==========\n");

    printf("Score: %d/%d (based on completed questions)\n",
           result.score, result.completed * MARKS);

    printf("Questions completed: %d/%d\n",
           result.completed, TOTAL);

    printf("Questions attempted: %d\n", result.attempted);
    printf("Correct answers: %d\n", result.correct);
    printf("Incorrect answers: %d\n",
           result.wrong - result.timedOut);
    printf("Timed-out questions: %d\n", result.timedOut);
    printf("Percentage: %.2f%%\n", result.percentage);

    if (result.completed == 0) {
        printf("No questions were completed.\n");
    } else if (result.percentage >= 80) {
        printf("Excellent performance!\n");
    } else if (result.percentage >= 60) {
        printf("Good job! Keep practicing.\n");
    } else if (result.percentage >= 40) {
        printf("You can do better. Keep learning!\n");
    } else {
        printf("You need more practice. Review the learning tips!\n");
    }

    printf("==================================\n");
}
