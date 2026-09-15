#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
void display(int guesses){
    switch(guesses){
        case 1:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 6:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 7:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        default:
            exit(1);
    }

}

void hang(char word[], int lettercount){

    char guessed[lettercount+1];
    for (int i = 0; i < lettercount; i++){
        guessed[i] = '_';
    }
    guessed[lettercount] = '\0';

    int wrongGuesses = 1;
    display(wrongGuesses);
    char guess;
    while (wrongGuesses < 7){
        printf("%s\n",guessed);
        scanf(" %c",&guess);
        char* check = strchr(word, guess);
        if(check == NULL){
            fflush(stdout);
            system("clear");
            printf("Wrong Guess!\n");
            wrongGuesses++;

            display(wrongGuesses);
        } else {
            while (check != NULL) {
                guessed[check-word] = guess;
                check = strchr(check + 1, guess);
                system("clear");
                display(wrongGuesses);
                if (strchr(guessed,'_') == NULL){
                    printf("You guessed right! The word was: %s\n",word);
                    exit(1);
                }
            }
        }
    }

    printf("You lost the game!\nThe word was %s\n",word);
    exit(1);
}
int main(){
    printf("Welcome to hangman!\n");
    srand(time(NULL));

    char choice;
    char *wordlist[] = {"elephant","ant", "baboon", "badger", "bat", "bear", "beaver", "camel", "cat", "clam", "cobra", "cougar", "coyote", "crow", "deer", "dog", "donkey", "duck", "eagle", "ferret", "fox", "frog", "goat", "goose", "hawk", "lion", "lizard", "llama", "mole", "monkey", "moose", "mouse", "mule", "newt", "otter", "owl", "panda", "parrot", "pigeon", "python", "rabbit", "ram", "rat", "raven", "rhino", "salmon", "seal", "shark", "sheep", "skunk", "sloth", "snake", "spider", "stork", "swan", "tiger", "toad", "trout", "turkey", "turtle", "weasel", "whale", "wolf", "wombat", "zebra"}; // You can add more words here if you'd like!

    printf("Choose '!' to quit, or '$' to begin a new game!\n");
    while (true){

        scanf("%c", &choice);
        if (choice == '!'){
            return 1;
        } else if (choice == '$'){
            system("clear");
            char word[10];
            strcpy(word, wordlist[rand()%64]);
            int lettercount = strlen(word);
            hang(word,lettercount);
        }
    }
    return 0;
}
