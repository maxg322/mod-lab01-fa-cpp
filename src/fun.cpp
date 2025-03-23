// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
   unsigned int sum = 0;
    bool foundNumber = false;
    bool isWord = false;

    while (*str) {
        if (!isspace(*str)) {
            if (!isWord) {  
                isWord = true;
                foundNumber = false;
            }
            if (isdigit(*str)) {
                foundNumber = true;
            }
        } else {  
            if (isWord) {  
                if (!foundNumber) {  
                    sum++;  
                }
                isWord = false;  
            }
        }
        str++;  
    }
    if (isWord && !foundNumber) {
        sum++;
    }
    return sum;
}

unsigned int faStr2(const char *str) {
    unsigned int sum = 0;
    bool isWord = false;
    bool isSuccessful = false;

    while (*str) {
        if (!isspace(*str)) {
            if (!isWord) {  
                isWord = true;
                isSuccessful = isupper(*str);
            } else {
                if (!islower(*str)) {
                    isSuccessful = false;
                }
            }
        } else {
            if (isWord && isSuccessful) {
                sum++;
            }
            isWord = false;
        }
        str++;
    }
    if (isWord && isSuccessful) {
        sum++;
    }
    return sum;
}

unsigned int faStr3(const char *str) {
    unsigned int length = 0;
    unsigned int currentLength = 0;
    unsigned int sumWords = 0;
    bool isWord = false;

    while (*str) {
        if (!isspace(*str)) {
            if (!isWord) {  
                isWord = true;
                currentLength = 1;
            } else {
                currentLength++;
            }
        } else {  
            if (isWord) {  
                length += currentLength;
                sumWords++;
                isWord = false;
            }
        }
        str++;
    }
    if (isWord) {
        length += currentLength;
        sumWords++;
    }
    if (sumWords == 0) {
        return 0;
    }
    return static_cast<unsigned int>(std::round(static_cast<double>(length) / sumWords));
}
