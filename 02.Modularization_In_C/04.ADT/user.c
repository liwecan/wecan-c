#include "array.h"
#include <stdio.h>

void printArray(Array_T array)
{
    
    for(int i=0; i<Array_getLength(array); i++){
        char *str = Array_getData(array, i);
        fputs(str, stdout);
    }
    fputs("\n", stdout);
}

int main()
{
    Array_T array = Array_new();

    Array_append(array,"My ");
    Array_append(array,"name ");
    Array_append(array,"is ");
    Array_append(array,"WeCan ");
    Array_append(array,"! ");

    printArray(array);

    Array_sort(array);

    printArray(array);

    Array_delete(array);
    return 0;
}
