// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* str1 = "hello world 123 test";
    const char* str2 = "Hello World test A Ab1";
    const char* str3 = "hello world test";
    std::cout << "Words without numbers: " << faStr1(str1) << std::endl;
    std::cout << "Words with uppercase first "
    "letter and lowercase others: " << faStr2(str2) << std::endl;
    std::cout << "Average word length: " << faStr3(str3) << std::endl;
    return 0;
}
