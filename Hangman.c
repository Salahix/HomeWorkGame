#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ATTEMPTS 6  // عدد المحاولات

// قائمة الكلمات لاختيار كلمة عشوائية منها
const char *word_list[] = {"hangman", "programming", "computer", "technology", "education"};
const int word_list_size = 5;

void choose_word(char *word) {
    int index = rand() % word_list_size;  // اختيار كلمة عشوائية
    strcpy(word, word_list[index]);
}

void display_word(const char *word, const char *guessed_letters) {
    for (int i = 0; i < strlen(word); i++) {
        if (strchr(guessed_letters, word[i])) {
            printf("%c ", word[i]);  // إذا تم تخمين الحرف، عرضه
        } else {
            printf("_ ");  // عرض _ إذا لم يتم تخمين الحرف
        }
    }
    printf("\n");
}

int main() {
    char word[50];
    char guessed_letters[50] = "";  // لحفظ الأحرف التي خمنها اللاعب
    int attempts = 0;  // عدد المحاولات
    int correct_guesses = 0;  // عدد الأحرف التي تم تخمينها بشكل صحيح
    int word_length;

    srand(time(0));  // تهيئة مولد الأرقام العشوائية
    choose_word(word);  // اختيار كلمة عشوائية
    word_length = strlen(word);

    printf("Welcome to Hangman Game!\n");
    printf("You have %d attempts to guess the word.\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS && correct_guesses < word_length) {
        char guess;
        printf("\nGuess a letter: ");
        scanf(" %c", &guess);

        // التحقق إذا كان الحرف قد تم تخمينه مسبقًا
        if (strchr(guessed_letters, guess)) {
            printf("You already guessed that letter. Try again.\n");
            continue;
        }

        // إضافة الحرف إلى قائمة الحروف المتوقعة
        guessed_letters[strlen(guessed_letters)] = guess;
        guessed_letters[strlen(guessed_letters) + 1] = '\0';

        // التحقق إذا كان الحرف موجودًا في الكلمة
        if (strchr(word, guess)) {
            printf("Correct guess!\n");
            correct_guesses++;
        } else {
            printf("Wrong guess!\n");
            attempts++;
        }

        // عرض الكلمة مع الأحرف التي تم تخمينها
        display_word(word, guessed_letters);

        // عرض المحاولات المتبقية
        printf("Attempts left: %d\n", MAX_ATTEMPTS - attempts);
    }

    if (correct_guesses == word_length) {
        printf("\nCongratulations! You've guessed the word: %s\n", word);
    } else {
        printf("\nGame over! The correct word was: %s\n", word);
    }

    return 0;
}
