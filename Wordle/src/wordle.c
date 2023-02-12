//
// Created by Kaitlyn Archambault on 2022-12-09.
//
#include "../inc/wordle.h"

void playGameLoop(struct CWordle *cWordle, char * outFilePath) {

    int currentGuess = 0;

    //populate the game board with neutral characters
    for (int i=0;i<cWordle->numGuesses;i++) {
        for(int j=0;j<cWordle->answerLength;j++) {
            strcpy(&cWordle->gameBoard[i][j], "_");
        }
    }

    printf("Welcome to C-Wordle!!\n");

    //print the initial game board:
    for (int i=0;i<cWordle->numGuesses;i++) {
        printf("%s\n", cWordle->gameBoard[i]);
    }

    while (currentGuess < cWordle->numGuesses && cWordle->guessedCorrectly == false) {

        //set the next empty line to the player's guess:
        strcpy(cWordle->gameBoard[currentGuess], takeUserInput(cWordle));

        //every time the game board is printed, apply colour coding to all past guesses.
        for (int i=0;i<cWordle->numGuesses;i++) {

            for (int j=0;j<cWordle->answerLength;j++) {

                    //print the updated gameBoard:
                    if (checkForGreen(j,i,cWordle)) {
                        printf("\033[0;32m"); //for a match in the right spot, make it green
                        printf("%c", cWordle->gameBoard[i][j]);

                    } else if (checkForYellow(j,i,cWordle)) {
                        printf("\033[1;33m"); //make it yellow if it matches a different index
                        printf("%c", cWordle->gameBoard[i][j]);

                    } else {
                        printf("\033[0m"); //reset colour
                        printf("%c", cWordle->gameBoard[i][j]);
                    }
            }
            //move to the next word/line
            printf("\n");
        }

        if (strcmp(cWordle->gameBoard[currentGuess], cWordle->answer) == 0) {
            cWordle->guessedCorrectly = true;
        }

        currentGuess++;
    }

    if (cWordle->guessedCorrectly) {
        printf("\033[0m"); //reset colour
        printf("You WIN!!!\nThe game result was written to the %s file.", outFilePath);
        //I'm not a big fan of how I passed the file path through to here
        //written to file in main.c
    } else {
        printf("\033[0m"); //reset colour
        printf("You LOSE!!!\nThe game result was written to the %s file.", outFilePath);
        //written to file in main.c
    }

    //figure out why this didn't work in main
    writeToFile(outFilePath, cWordle);

}

bool checkForGreen(int currentLetter, int currentGuess, struct CWordle *cWordle) {

    if (cWordle->gameBoard[currentGuess][currentLetter] == cWordle->answer[currentLetter]) {
        return true;
    } else {
        return false;
    }
}

bool checkForYellow(int currentLetter, int currentGuess, struct CWordle *cWordle) {

    //checking for yellow is why I moved everything out to dedicated methods,
    //because only this case requires a third loop.
    for (int i=0;i<cWordle->answerLength;i++) {
        if (cWordle->gameBoard[currentGuess][currentLetter] == cWordle->answer[i] && i != currentLetter) {
            return true;
        }
    }

    return false;
}

const char * takeUserInput(struct CWordle *cWordle) {

    //allot the space for them to enter way too long of a word, it'll get validated later
    static char guessedWord[MAX_STRING_LENGTH];

    printf("\033[0m"); //reset colour
    printf("Please enter a %d-letter word: ", cWordle->answerLength);
    scanf(" %s", guessedWord);

    //change to all uppercase for comparison later:
    for (int i=0;i<MAX_STRING_LENGTH;i++) {
        guessedWord[i] = toupper(guessedWord[i]);
    }

    return validateInput(cWordle, guessedWord);
}

const char * validateInput(struct CWordle *cWordle, const char *playerGuess) {

//    //for dictionary api, maybe move to its own method?
//    CURL *curl;
//    CURLcode response;
//    char responseString[250];
//
//    curl_global_init(CURL_GLOBAL_ALL);
//    curl=curl_easy_init();
//
//    char requestURL[] = {"https://api.dictionaryapi.dev/api/v2/entries/en/"};
//    strcat(requestURL,playerGuess);

    bool validated = false;

    do {
        if (strlen(playerGuess) != cWordle->answerLength) {

            printf("Sorry, but you can only enter %d-letter words.\n", cWordle->answerLength);
            validated = false;
            takeUserInput(cWordle);

        } else {
            validated = true;
        }
        for (int i=0;i< strlen(playerGuess);i++) {
            if (isalpha(playerGuess[i]) == 0) { //isalpha will return 0 for non-alphabetic characters

                printf("Sorry, but you can only enter %d-letter words.\n", cWordle->answerLength);
                validated = false;
                takeUserInput(cWordle);

            } else {
                validated = true;
            }
        }

//        if (curl) {
//
//            curl_easy_setopt(curl, CURLOPT_URL, requestURL);
//            //supress from writing to console:
//            curl_easy_setopt(curl, CURLOPT_NOBODY,1);
//            //don't allow redirects:
//            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
//
//            response = curl_easy_perform(curl);
//
//            if (response != CURLE_OK) {
//                fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(response));
//                validated = false;
//            }
//
//
//        }

    } while (!validated);

    return playerGuess;
}