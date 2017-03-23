#include <stdlib.h>
#include <string.h>
#include "array.h"

#define MAX_ELEMENTS 256

struct Array{
    void *elements[MAX_ELEMENTS];
    int numOfElements;
};

//====================================================
Array_T Array_new(void)
{
    Array_T array = malloc(sizeof(struct Array));
    array->numOfElements = 0;

    return array;
}

void Array_delete(Array_T array)
{
    free(array);
}

//===================================================
int Array_getLength(Array_T array)
{
    return array->numOfElements;
}

void *Array_getData(Array_T array, int index)
{
    return array->elements[index];
}

//----------------------------------------------------
int Array_getIndex(Array_T array, void *pData)
{
    for(int index=0; index < array->numOfElements; index++){
        if(array->elements[index] == pData){
            return index;
            break;
        }
    }

    return -1;
}

//---------------------------------------------------
void Array_append(Array_T array, void *pData)
{
    int index=array->numOfElements;
    array->elements[index] = pData;
    array->numOfElements++;
}

void Array_replace(Array_T array, int index, void *pData)
{
    array->elements[index] = pData;
}

void Array_insert(Array_T array, int index, void *pData)
{
    for(int i=array->numOfElements; i>index; i--)
        array->elements[i] = array->elements[i-1];

    array->elements[index] = pData;
    array->numOfElements++;
}

void Array_remove(Array_T array, int index)
{
    for(int i = index+1; i < array->numOfElements; i++)
        array->elements[i-1] = array->elements[i];

    array->numOfElements--;
}

void Array_sort(Array_T array)
{
    for(int i=0; i < array->numOfElements; i++){
        for(int j=i+1; j < array->numOfElements; j++){
            if(strcmp(array->elements[i], array->elements[j]) > 0){ 
                char *swap = array->elements[i];
                array->elements[i] = array->elements[j];
                array->elements[j] = swap;
            }
        }
    }
}

