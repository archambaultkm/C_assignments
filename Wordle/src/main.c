#include "../inc/wordle.h"

int main(int argc, char *argv[]) {

    char * inFilePath;
    char * outFilePath;
    struct CWordle cWordle;

    setbuf(stdout, NULL);

    if (argc != EXPECTED_ARGS) {

        fprintf(stderr, "Invalid number of command line arguments.");
        return 1;

    } else if (!(strcmp(argv[1],"-i") == 0) && !(strcmp(argv[1],"-o") == 0) || !(strcmp(argv[3],"-i") == 0) && !(strcmp(argv[3],"-o") == 0)) {

        fprintf(stderr, "Invalid command line argument usage.");
        return 1;

    } else {

        //find out which arguments represent which files
        for (int i=0;i<argc;i++) {

            if (strcmp(argv[i],"-i") == 0) {

                inFilePath = argv[i+1];

                if (!validFile(inFilePath, "r")) {
                    fprintf(stderr, "Cannot open %s for reading!\n", inFilePath);
                    return 1;
                }

            } else if (strcmp(argv[i],"-o") == 0) {

                outFilePath = argv[i + 1];

                if (!validFile(outFilePath, "a")) {
                    fprintf(stderr, "Cannot open %s for writing!\n", outFilePath);
                    return 1;
                }
            }
        }

        readFromFile(inFilePath, &cWordle);
    }

    //pass off to wordle.c:
    buildGame(&cWordle, outFilePath);

    return 0;

} //end main

bool validFile(char * filePath, char * flag) {

    FILE * fileptr = fopen(filePath, flag);

    if (fileptr == NULL) {
        fclose(fileptr);
        return false;

    } else {
        fclose(fileptr);
        return true;
    }
}

void readFromFile(char *filePath, struct CWordle *cWordle) {

    char fullLine[MAX_STRING_LENGTH];
    char *c;

    cWordle->inFile = fopen(filePath, "r");

    //word length is the first number on the first line, guesses is the second
    fgets(fullLine, MAX_STRING_LENGTH, cWordle->inFile);

    c = strtok(fullLine, " ");
    cWordle->answerLength = atoi(c);

    c = strtok(NULL, " ");
    cWordle->numGuesses = atoi(c);

    //since the word will always be the whole second line of a file,
    //it's simplest to do this:
    fgets(cWordle->answer, MAX_STRING_LENGTH, cWordle->inFile);
    fclose(cWordle->inFile);

}

void writeToFile(char *filePath, struct CWordle *cWordle) {

    cWordle->outFile = fopen(filePath, "a");

    //print the outcome of the last game:

    if (cWordle->guessedCorrectly) {
        fprintf(cWordle->outFile, "The solution was found.\n");
    } else {
        fprintf(cWordle->outFile, "The solution was not found.\n");
    }

    for (int i=0;i<cWordle->numGuesses;i++) {
        fprintf(cWordle->outFile, "%s\n", cWordle->gameBoard[i]);
    }

}

void buildGame(struct CWordle *cWordle, char * outFilePath) {

    //allocate the array here then pass it into functions in wordle.c
    cWordle->gameBoard = (char**) calloc(cWordle->numGuesses, sizeof(char*));

    for (int i=0;i<cWordle->numGuesses;i++) {
        cWordle->gameBoard[i] = (char*) calloc(cWordle->answerLength, sizeof(char));
    }

    //start the game with the allocated space:
    playGameLoop(cWordle, outFilePath);

    //Free the memory
    //first free the "inner elements"
    for (int i=0;i<cWordle->numGuesses;i++) {
        free(cWordle->gameBoard[i]);
    }
    //free the outer array:
    free(cWordle->gameBoard);
}


