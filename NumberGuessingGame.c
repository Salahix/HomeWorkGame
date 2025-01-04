#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   int target, guess,attempts = 0;

   srand(time(NULL));

   target = rand() %100 +1;

   printf("_______Welcomet to the Number Guessing game!_______\n|      Guless a number between 1 and 100.       |\n");

   while(1){
      printf("|          Enter your guess:");
      scanf("%d", &guess);
      attempts++;

      if (guess > target){
         printf("|          Too high! Try again.\n");
      }else if (guess <target) {
         printf("|          Too low! Try again. \n");

      }else{
         printf("|____Correct! You've guessed the number in %d attempts._______|\n", attempts);
         break;
      }
   }
   return 0;
}
