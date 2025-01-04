#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* choices[] = {"rock", "paper", "scissors"};

int main() {
    char userChoice[10];
    int computerChoice, userChoiceIndex;
    char playAgain;

    srand(time(NULL));

    do {
        printf("Enter 'rock', 'paper', or 'scissors': ");
        scanf("%s", userChoice);


        if (strcmp(userChoice, "rock") == 0) {
            userChoiceIndex = 0;
        } else if (strcmp(userChoice, "paper") == 0) {
            userChoiceIndex = 1;
        } else if (strcmp(userChoice, "scissors") == 0) {
            userChoiceIndex = 2;
        } else {
            printf("Invalid choice. Please choose 'rock', 'paper', or 'scissors'.\n");
            continue;
        }


        computerChoice = rand() % 3;
        printf("Computer chose: %s\n", choices[computerChoice]);

        if (userChoiceIndex == computerChoice) {
            printf("It's a draw!\n");
        } else if ((userChoiceIndex == 0 && computerChoice == 2) ||
                   (userChoiceIndex == 1 && computerChoice == 0) ||
                   (userChoiceIndex == 2 && computerChoice == 1)) {
            printf("You win!\n");
        } else {
            printf("Computer wins!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
