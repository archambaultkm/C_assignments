#include "../inc/crypt.h"

void encryptMessage(char inputMessage[]) {

    char charToShift;
    unsigned int messageToInt[ARRAYSIZE] = {0};
    unsigned int mask = 0xa5;
    char printableChars[VALID_CHARS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                                        'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '#', '$',
                                        '%', '&', '(', ')', ':', ';', '?', '.', ',', '/'};

    for (int i=0;i<ARRAYSIZE;i++) {

        //only shift characters until the array is empty
        if (inputMessage[i] != '\0') {

            charToShift = toupper(inputMessage[i]);

            for (int j = 0; j < VALID_CHARS; j++) {

                //brute-force check against every valid character
                if (charToShift == printableChars[j]) {
                    charToShift = (printableChars[(j - SHIFT_KEY + VALID_CHARS) % VALID_CHARS]);
                    messageToInt[i] = (int)charToShift;

                } else if (charToShift == ' ') {
                    messageToInt[i] = (int)charToShift;
                }
            }
            printf("%d ", CRYPT(messageToInt[i], mask));
        }
    }
}

unsigned int * convertToInt(char inputMessage[], unsigned int intsToDecrypt[]) {
    char* token = strtok(inputMessage, " ");
    int i=0;

    while (token != NULL) {
        intsToDecrypt[i] = atoi(token);
        i++;
        token = strtok(NULL, " ");
    }

    return intsToDecrypt;
}

void decryptMessage(char inputMessage[]) {
    char charToShift;
    char decryptedMessage[ARRAYSIZE] = {0};
    unsigned int intsToDecrypt[ARRAYSIZE] = {0};
    unsigned int mask = 0xa5;

    char printableChars[VALID_CHARS] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                                        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                                        'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                                        'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '#', '$',
                                        '%', '&', '(', ')', ':', ';', '?', '.', ',', '/'};

    //convert the entered message to an array of ints
    convertToInt(inputMessage, intsToDecrypt);

    for (int i=0;i<ARRAYSIZE;i++) {
        //only shift characters until the array is empty
        if (intsToDecrypt[i] != '\0') {

            charToShift = (char)CRYPT(intsToDecrypt[i], mask);

            for (int j = 0; j < VALID_CHARS; j++) {

                if (charToShift == printableChars[j]) {
                    //shift back the other way to decrypt
                    charToShift = (printableChars[(j + SHIFT_KEY + VALID_CHARS) % VALID_CHARS]);

                    decryptedMessage[i] = charToShift;
                    //break the for loop so that it doesn't shift again when it has to wrap around (idk why it did but this fixed it)
                    break;

                } else if (charToShift == ' ') {
                    decryptedMessage[i] = charToShift;
                }
            }
            printf("%c", decryptedMessage[i]);
        }
    }
}