#include "../inc/crypt.h"

int main() {
    int exitCode = 0;
    enum process processInput;

    //initialize to zero so that the entire array doesn't need to be used:
    char inputMessage[ARRAYSIZE] = {0};

    //start the app by prompting them to choose either encrypt or decrypt
    printf("What operation would you like to perform (1 - Encrypt, 2 - Decrypt)? ");
    scanf("%d", &processInput);

    switch (processInput) {
        case ENCRYPTING:
            printf("So, you want to encrypt the message!\nPlease enter your message: ");
            //This will work to read in a string with spaces:
            scanf(" %[^\n]s", inputMessage);
            // pass to function in crypt.c
            encryptMessage(inputMessage);

            break;

        case DECRYPTING:
            printf("So, you want to decrypt the message!\nPlease enter your message: ");
            scanf(" %[^\n]s", inputMessage);
            decryptMessage(inputMessage);

            break;

        default:
            printf("So, you do not know what you want!");
            exitCode = 1;
    }

    return exitCode;
}
