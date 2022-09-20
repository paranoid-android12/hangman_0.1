#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char word[20];
char disp[] = {};
char guess[20];
int lives = 5;

int do_comm()
{
    for (int i = 0; i < 20; i++)
    {
        if (guess[0] == word[i])
        {
            disp[i] = guess[0];
        }
    }
    for (int i = 0; i < strlen(word); i++)
    {
        if (disp[i] == '-')
        {
            men_loop();
        }
    }
    printf("YOU WON!!!!!!!");
    exit(0);
}

int check_exist()
{
    // Checks if the guess exists in the word, if yes, then replace each '-' with the guessed letter.
    for (int i = 0; i < 20; i++)
    {
        if (guess[0] == word[i])
        {
            do_comm();
        }
    }
    lives--;
    men_loop();
}

int men_loop()
{
    // Main loop, checks if you lose
    printf("\n\n\n/////////\n HANGMAN GAME\n\nLives left: %d\n\n\n\n", lives);

    if (lives < 1)
    {
        printf("You Lose!");
        exit(0);
    }

    // Prints the frame
    for (int i = 0; i < strlen(word); i++)
    {
        printf("%c", disp[i]);
    }

    // Takes player input of the letter
    printf("\nPlease enter a guess: ");
    scanf("%s", &guess);
    check_exist();
}
int main()
{
    // Main start: Choose the word
    printf("Enter the word:\n");
    scanf("%s", &word);

    // Creates initial frame, initialize the '-' based on the amount of letters in word
    printf("\n\n\n/////////\n HANGMAN GAME\n\n\n\n\n\n");
    for (int i = 0; i < strlen(word); i++)
    {
        disp[i] = '-';
        printf("%c", disp[i]);
    }

    men_loop();
}