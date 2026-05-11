#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // ROCK PAPER SCISSORS GAME
  srand(time(NULL));

  printf("\n\n\t||ROCK PAPER & SCISSORS||\n\n");

  int exitGame = 0;
  int no_of_wins = 0;
  int no_of_loses = 0;
  int no_of_draws = 0;
  int showScore = 0;

  char *options[] = {"Rock", "Paper", "Scissors"};

  printf("0. Enter 0 to PLAY game!\n");
  printf("1. Enter 1 to EXIT game!\n");
  scanf("%d", &exitGame);

  if (exitGame == 1) {
    printf("Exiting game!......\n");
    return 0;
  } else {
    while (exitGame == 0) {
      int compChoice = (rand() % 3) + 1;
      int userChoice = 0;

      printf("Choose:\n");
      printf("\t1. Rock\n");
      printf("\t2. Paper\n");
      printf("\t3. Scissors\n");
      scanf("%d", &userChoice);
      while ((getchar()) != '\n')
        ;

      printf("You chose: %s!\n", options[userChoice - 1]);
      printf("Computer chose: %s!\n", options[compChoice - 1]);

      if (userChoice == compChoice) {
        printf("It's a draw!\n");
        no_of_draws++;
      } else if ((userChoice == 1 && compChoice == 2) ||
                 (userChoice == 2 && compChoice == 3) ||
                 (userChoice == 3 && compChoice == 1)) {
        printf("You Lose!\n");
        no_of_loses++;
      } else if ((userChoice == 1 && compChoice == 3) ||
                 (userChoice == 2 && compChoice == 1) ||
                 (userChoice == 3 && compChoice == 2)) {
        printf("You win!\n");
        no_of_wins++;
      } else {
        while ((getchar()) != '\n')
          ;
        printf("Invalid input!! Press enter to continue!\n");
        getchar();
      }

      printf("0. Replay!\n");
      printf("1. Exit!\n");
      scanf("%d", &exitGame);

      if (exitGame == 0) {
        printf("Restarting game!!....\n");
        system("clear");
      }
    }

    printf("Do you want to print the scorecard of this gaming session?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%d", &showScore);
    while ((getchar()) != '\n')
      ;

    if (showScore == 1) {
      float total_games = no_of_draws + no_of_loses + no_of_wins;
      system("clear");
      printf("You won total of %d game(s)\n", no_of_wins);
      printf("You lost total of %d game(s)\n", no_of_loses);
      printf("You had total of %d draw game(s)\n", no_of_draws);
      printf("Your overall accuracy is: %.2f%%\n",
             ((float)no_of_wins / (total_games)) * 100);
    }

    printf("Exiting Game!!.....\n");
  }

  return 0;
}