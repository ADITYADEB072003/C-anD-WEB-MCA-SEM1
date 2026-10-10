#include <stdio.h>
#include <time.h>
#define TOTAL 5
#define OPTIONS 4

typedef struct Result {
  int score;
  int correct;
  int wrong;
  float percentage;
} Result;

void displayquestion(int i, char question[][100], char options[][OPTIONS][100]);
void showresult(Result result);

int main() {
  int answer;
  time_t start, end;
  char question[TOTAL][100] = {"What is the capital of France?",
                               "Which planet is known as the Red Planet?",
                               "What is the largest ocean on Earth?",
                               "Who wrote the play 'Romeo and Juliet'?",
                               "What is the chemical symbol for gold?"};
  char options[TOTAL][OPTIONS][100] = {
      {"A. Paris", "B. London", "C. Berlin", "D. Madrid"},
      {"A. Earth", "B. Mars", "C. Jupiter", "D. Saturn"},
      {"A. Atlantic Ocean", "B. Indian Ocean", "C. Arctic Ocean",
       "D. Pacific Ocean"},
      {"A. William Shakespeare", "B. Charles Dickens", "C. Mark Twain",
       "D. Jane Austen"},
      {"A. Au", "B. Ag", "C. Fe", "D. Hg"}};

  // for (int i = 0; i < TOTAL; i++) {
  //     for (int j = 0; j < OPTIONS; j++) {
  //       printf("%s\n", options[i][j]);
  //     }
  //     printf("\n");
  // }

  int a = 1, b = 2, c = 3, d = 4;
  int *correctAnswers[TOTAL] = {&a, &b, &d, &a,
                                &a}; // Correct options (1-based index)
  Result result = {0, 0, 0, 0.0};

  printf("Welcome to the Quiz!\n");
  printf("You will be asked %d questions. Please answer by entering the option "
         "number (1-4).\n",
         TOTAL);
  printf("You have 30 seconds to answer each question. Let's begin!\n\n");
  for (int i = 0; i < TOTAL; i++) {
    displayquestion(i, question, options);
    start = time(NULL);
    printf("Your answer: ");

    if (scanf("%d", &answer) != 1) {
      printf("Invalid input! .\n");

      return 1;
    }
    end = time(NULL);

    if (difftime(end, start) > 3) {
      printf("Time's up! Moving to the next question.\n");
      result.wrong++;
      continue;
    }
    if (answer < 1 || answer > 4) {
      printf("Invalid Input!");
      result.wrong++;
      continue;
    }

    if (answer == *correctAnswers[i]) {
      printf("Correct!\n\n");
      result.score += 10; // Assuming each correct answer gives 10 points
      result.correct++;
    } else {
      printf("Wrong! The correct answer was option %d.\n\n",
             *correctAnswers[i]);
      result.wrong++;
    }
  }
  result.percentage = (float)result.correct / TOTAL * 100;
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
  printf("\nQuiz Completed!\n");
  printf("Score: %d\n", result.score);
  printf("Correct Answers: %d\n", result.correct);
  printf("Wrong Answers: %d\n", result.wrong);
  printf("Percentage: %.2f%%\n", result.percentage);

  if (result.percentage >= 80) {
    printf("Excellent performance!\n");
  } else if (result.percentage >= 60) {
    printf("Good job! Keep practicing.\n");
  } else if (result.percentage >= 40) {
    printf("You can do better. Keep trying!\n");
  } else {
    printf("You need more practice. \n");
  }
}