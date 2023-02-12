//
// Created by Kaitlyn Archambault on 2022-11-10.
//

#ifndef ASSIGN4_CRYPT_H
#define ASSIGN4_CRYPT_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

enum process {
    ENCRYPTING = 1,
    DECRYPTING = 2
};

#define ARRAYSIZE 256
#define VALID_CHARS 50
#define SHIFT_KEY 6

#define CRYPT(inputArray, mask) ((inputArray) ^ (mask))


void encryptMessage(char[]);
void decryptMessage(char[]);
unsigned int * convertToInt(char[], unsigned int[]);

#endif //ASSIGN4_CRYPT_H
