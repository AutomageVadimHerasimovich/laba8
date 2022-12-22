//
// Created by Вадим Герасимович on 12/20/22.
//

#ifndef LABA8_FUN_H
#define LABA8_FUN_H
#include <stdio.h>
#include <stdlib.h>
#include "locale.h"

int count_chet_words(const char* string);
int len(char* string);
void hoar_sort(char** strings, int left, int right, int(*compareFunc)(char*), int(fun)(int*));
void result(int argc, char** argv, int*max);
int count_max_len(char** str, int* length, int* max);
int donat();
#endif //LABA8_FUN_H
