//
// Created by Вадим Герасимович on 12/20/22.
//
#include "fun.h"
#include <stdio.h>
int is_letter(char string) {
    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z'))
        return 1;
    return 0;
}

int len(char* string) {
    int i = 0;
    for (; string[i] != '\0'; i++);
    return i;
}

int len_test(char* string, int max) {
    int i = 0,fin = 0, start = 0,n;;
    if (max<len(string)){
        max=len(string);
    }
    return max;
    /*for (int i = len(string); i != 0; i--) {
        if (is_letter(string[i - 1]) && !is_letter(string[i])) {
            start = i;
            continue;
        }
        if (!is_letter(string[i + 1]) && is_letter(string[i])) {
            fin=i;
            start = 0;
            n=fin-start;
            if (max<n){
                max=n-max-2;
                return max;
            }
        }

    }

    /*for (int n=0; string[i] != '\0'; i++){
        n++;
        if (!is_letter(string[i])) {
            max++;
            if (max < n+1) {
                max = n-1;
                return max;
            }
        }
    }*/
}

int count_chet_words(const char* string) {
    int words = 0, start = 0;
    for (int i = len(string); i != 0; i--) {
        if (is_letter(string[i - 1]) && !is_letter(string[i])) {
            start = i;
            continue;
        }
        if (!is_letter(string[i - 1]) && is_letter(string[i])) {
            words += ((start - i) % 2 == 0);
            start = 0;
        }
    }
    if (is_letter(string[0]) && start != 0)
        words += (start % 2 == 0);
    return words;
}

int count_max_len(char** str, int* length, int* max) {
         for (int i = 0; i < len(str); i++) {
             int k = 0;
             max[i] = 999;
             for (int j = 0; j < length[i]; j++) {
                 k++;
                 if (str[i][j + 1] == ' ' || str[i][j + 1] == '\0' || str[i][j + 1] == '\n') {
                     if (max[i] > k) {
                         max[i] -= k;
                     }
                     k = -1;
                 }
             }
         }
         return max;
     }

void swap(char** first, char** second)
{
    char* temp = *first;

    *first = *second;
    *second = temp;
}

int partition(char** strings, int left, int right, int(*compareFunc)(char*))
{
    int pivot = compareFunc(strings[right]);
    int pivotIndex = left;

    for (int i = left; i < right; i++)
    {
        if (compareFunc(strings[i]) <= pivot)
        {
            swap(&strings[i], &strings[pivotIndex]);
            pivotIndex++;
        }
    }

    swap(&strings[pivotIndex], &strings[right]);

    return pivotIndex;
}
void hoar_sort(char** strings, int left, int right, int(*compareFunc)(char*), int(fun)(int*)){
    if (left >= right)
        return;

    int p = partition(strings, left, right, compareFunc);

    hoar_sort(strings, left, p - 1, compareFunc, fun);
    hoar_sort(strings, p + 1, right, compareFunc, fun);
}
void result(int argc, char** argv, int *max) {
    for (int i = 1; i < argc; i++)
        printf("Строка: %s с %d with max len %d\n", argv[i], count_chet_words(argv[i]), count_max_len(argv[i], argc,max[i]));
}
void copy_arr(char**res, char** result, int argc){
    for (int i = 0; i < argc; ++i) {
        for (int j = 0; j < len(res); ++j) {
            *(*(result+i)+j)=*(*(res+i)+j);
        }
    }
}
void delete_string(char** arr, int argc){
    for (int i = 0; i < argc-1; ++i) {
        *(arr+i)=*(arr+i+1);
    }
}
void copy(char** arr, char** copyr, char argc){
    copy_arr(arr, copyr,argc);
    delete_string(arr,argc);
    argc--;
}
#include <math.h>
#include <memory.h>
#include <unistd.h>

int donat() {
        float A = 0, B = 0;
        float i, j;
        int k;
        float z[1760];
        char b[1760];
        printf("\x1b[2J");
        for(i=0;i<1761;i++) {
            memset(b,32,1760);
            memset(z,0,7040);
            for(j=0; j < 6.28; j += 0.07) {
                for(i=0; i < 6.28; i += 0.02) {
                    float c = sin(i);
                    float d = cos(j);
                    float e = sin(A);
                    float f = sin(j);
                    float g = cos(A);
                    float h = d + 2;
                    float D = 1 / (c * h * e + f * g + 5);
                    float l = cos(i);
                    float m = cos(B);
                    float n = sin(B);
                    float t = c * h * g - f * e;
                    int x = 40 + 30 * D * (l * h * m - t * n);
                    int y= 12 + 15 * D * (l * h * n + t * m);
                    int o = x + 80 * y;
                    int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                    if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                        z[o] = D;
                        b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                    }
                }
            }
            printf("\x1b[1;31m");
            for(k = 0; k < 1761; k++) {
                putchar(k % 80 ? b[k] : 10);
                A += 0.00004;
                B += 0.00002;
            }
            usleep(30000);
        }

    }