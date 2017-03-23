#include "array.h"
#include <stdio.h>

void printString(Array_T array)
{
    for(int i=0; i<Array_getLength(array); i++){
        char *str = (char *) Array_getData(array, i);
        fputs(str, stdout);
        fputs(" ", stdout);
    }
    fputs("\n", stdout);
}

void printNum(Array_T array)
{
    for(int i=0; i<Array_getLength(array); i++){
        int *num = (int *) Array_getData(array, i);
        printf("%5d", *num);
    }
    printf("\n");
}

int main()
{
    Array_T arrayStr = Array_new();
    Array_T arrayNum = Array_new();
    const int num1=11, num2=29, num3=83, num4=-4, num5=30;

    Array_append(arrayStr, (void *) "My");
    Array_append(arrayStr, (void *) "name");
    Array_append(arrayStr, (void *) "is");
    Array_append(arrayStr, (void *) "WeCan");
    Array_append(arrayStr, (void *) "! ");

    printf("Test string: \n");
    printString(arrayStr);
    Array_sort(arrayStr);
    printString(arrayStr);

    Array_append(arrayNum, (void *) &num1);
    Array_append(arrayNum, (void *) &num2);
    Array_append(arrayNum, (void *) &num3);
    Array_append(arrayNum, (void *) &num4);
    Array_append(arrayNum, (void *) &num5);

    printf("\nTest number: \n");
    printNum(arrayNum);
    Array_sort(arrayNum);
    printNum(arrayNum);

    Array_delete(arrayStr);
    Array_delete(arrayNum);
    return 0;
}
