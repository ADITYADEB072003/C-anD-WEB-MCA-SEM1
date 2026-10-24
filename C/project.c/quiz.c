#include <stdio.h>
#include <time.h>

#define TOTAL 5
#define OPTIONS 4
#define TIME_LIMIT 30

typedef struct Result {
    int score;
    int correct;
    int wrong;
    float percentage;
} Result;

void displayquestion(int i, char question[][100],
                     char options[][OPTIONS][100]);
void showresult(Result result);

int main() {
    int answer;
    time_t start, end;

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

    int correctAnswers[TOTAL] = {1, 2, 4, 1, 1};

    char explanation[TOTAL][150] = {
        "Paris is the capital city of France.",
        "Mars appears red because of iron oxide on its surface.",
        "The Pacific Ocean is the largest ocean on Earth.",
        "William Shakespeare wrote Romeo and Juliet.",
        "Au comes from the Latin word Aurum, meaning gold."
    };

    Result result = {0, 0, 0, 0.0};

    printf("Welcome to the Quiz!\n");
    printf("You will be asked %d questions.\n", TOTAL);
    printf("Enter an option number between 1 and %d.\n", OPTIONS);
    printf("You have %d seconds per question.\n\n", TIME_LIMIT);

    for (int i = 0; i < TOTAL; i++) {
        displayquestion(i, question, options);

        start = time(NULL);
        printf("Your answer: ");

        if (scanf("%d", &answer) != 1) {
            int ch;

            printf("Invalid input! Please enter a number.\n");

            while ((ch = getchar()) != '\n' && ch != EOF);

            if (ch == EOF) {
                printf("\nInput ended. Quiz terminated.\n");
                break;
            }

            i--;
            continue;
        }

        end = time(NULL);

        if (difftime(end, start) > TIME_LIMIT) {
            printf("Time's up! Moving to the next question.\n\n");
            result.wrong++;
            continue;
        }

        if (answer < 1 || answer > OPTIONS) {
            printf("Invalid option! Enter a number from 1 to %d.\n\n",
                   OPTIONS);
            i--;
            continue;
        }

        if (answer == correctAnswers[i]) {
            printf("Correct answer!\n\n");
            result.score += 10;
            result.correct++;
        } else {
            printf("Wrong answer!\n");
            printf("Correct answer: %s\n",
                   options[i][correctAnswers[i] - 1]);
            printf("Learning tip: %s\n\n", explanation[i]);

            result.wrong++;
        }
    }

    result.percentage = (float)result.score / (TOTAL * 10) * 100;

    showresult(result);

    return 0;
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
    printf("Score: %d/%d\n", result.score, TOTAL * 10);
    printf("Correct answers: %d\n", result.correct);
    printf("Wrong answers: %d\n", result.wrong);
    printf("Percentage: %.2f%%\n", result.percentage);

    if (result.percentage >= 80) {
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