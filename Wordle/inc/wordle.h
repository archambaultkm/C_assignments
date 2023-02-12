//
// Created by Kaitlyn Archambault on 2022-12-09.
//

#ifndef ASSIGN5_WORDLE_H
#define ASSIGN5_WORDLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <curl/curl.h>

#define MAX_STRING_LENGTH 250 //allow out-of bounds strings to be validated
#define EXPECTED_ARGS 5

struct CWordle {
    int numGuesses;
    int answerLength;
    char ** gameBoard;
    FILE * inFile;
    FILE * outFile;
    bool guessedCorrectly;
    const char answer[];
};

void readFromFile(char *, struct CWordle *);
void writeToFile(char *, struct CWordle *);
bool validFile(char *, char *);

void buildGame(struct CWordle *, char *);
void playGameLoop(struct CWordle *, char *);

bool checkForGreen(int, int, struct CWordle *);
bool checkForYellow(int, int, struct CWordle *);

const char * takeUserInput(struct CWordle *);
const char * validateInput(struct CWordle *, const char *);

#endif //ASSIGN5_WORDLE_H
