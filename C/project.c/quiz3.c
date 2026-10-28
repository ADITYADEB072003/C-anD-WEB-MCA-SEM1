
#include <stdio.h>
#include <time.h>

#define TOTAL 5
#define OPTIONS 4
#define TIME_LIMIT 30

typedef struct {
    int score;
    int correct;
    int wrong;
    int timeout;
    int attempted;
} Result;

void displayQuestion(int i, char question[][100],
                     char options[][OPTIONS][100]);

void showResult(Result r);

int main() {
    int answer, ch;
    time_t start, end;

    char question[TOTAL][100] = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "What is the largest ocean on Earth?",
        "Who wrote Romeo and Juliet?",
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

    int correctAnswers[TOTAL] = {1, 2, 4, 1, 1};

    char explanation[TOTAL][150] = {
        "Paris is the capital of France.",
        "Mars appears red because of iron oxide.",
        "The Pacific is the largest ocean.",
        "William Shakespeare wrote the play.",
        "Au comes from the Latin word Aurum."
    };

    Result r = {0};

    printf("Welcome to the Quiz!\n");
    printf("You have %d seconds per question.\n\n", TIME_LIMIT);

    for (int i = 0; i < TOTAL; i++) {

        displayQuestion(i, question, options);

        while (1) {
            start = time(NULL);

            printf("Your answer (1-%d): ", OPTIONS);

            if (scanf("%d", &answer) != 1) {
                printf("Invalid input! Enter a number.\n");

                while ((ch = getchar()) != '\n' && ch != EOF);

                if (ch == EOF) {
                    printf("Input ended.\n");
                    goto finish;
                }

                continue;
            }

            /* Remove any extra characters on this input line. */
            ch = getchar();

            while (ch != '\n' && ch != EOF) {
                ch = getchar();
            }

            end = time(NULL);

            if (difftime(end, start) > TIME_LIMIT) {
                printf("Time's up!\n");
                r.wrong++;
                r.timeout++;
                r.attempted++;
                break;
            }

            if (answer < 1 || answer > OPTIONS) {
                printf("Choose an option from 1 to %d.\n\n",
                       OPTIONS);
                continue;
            }

            r.attempted++;

            if (answer == correctAnswers[i]) {
                printf("Correct answer!\n\n");
                r.score += 10;
                r.correct++;
            } else {
                printf("Wrong answer!\n");
                printf("Correct answer: %s\n",
                       options[i][correctAnswers[i] - 1]);
                printf("Learning tip: %s\n\n", explanation[i]);

                r.wrong++;
            }

            break;
        }
    }

finish:
    showResult(r);

    return 0;
}

void displayQuestion(int i, char question[][100],
                     char options[][OPTIONS][100]) {
    printf("\nQuestion %d: %s\n", i + 1, question[i]);

    for (int j = 0; j < OPTIONS; j++) {
        printf("%d. %s\n", j + 1, options[i][j]);
    }
}

void showResult(Result r) {
    printf("\n========== QUIZ RESULTS ==========\n");

    printf("Score: %d/%d\n", r.score, r.attempted * 10);
    printf("Correct answers: %d\n", r.correct); 
    printf("Wrong answers: %d\n", r.wrong - r.timeout);
    printf("Timed-out questions: %d\n", r.timeout);

    if (r.attempted > 0) {
        printf("Percentage: %.2f%%\n",
               (float)r.score / (r.attempted * 10) * 100);
    } else {
        printf("Percentage: 0.00%%\n");
    }

    if (r.correct >= 4 && r.attempted == TOTAL) {
        printf("Excellent performance!\n");
    } else if (r.correct >= 3) {
        printf("Good job! Keep practicing.\n");
    } else {
        printf("Keep learning and try again!\n");
    }

    printf("==================================\n");
}
