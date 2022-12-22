#include <stdio.h>
#include "fun.h"

int main(int argc, char** argv){
    int* max;
    if (argc == 1){
        printf("Ошибка.Нет аргумента");
        return 0;
    }
    hoar_sort(argv, 1, argc - 1,&count_chet_words ,&count_max_len);
    printf("Отсортированный методом Хоара массив строк по количеству слов состоящим из четного количества символов:\n");
    result(argc, argv, count_max_len(argv,argc,max));
    /*printf("\nНажмите 'return'\n");
    if (getchar()) {
        donat();
    }*/
    return 0;
}