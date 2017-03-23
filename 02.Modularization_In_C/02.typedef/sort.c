#include <stdio.h>
#include <stdlib.h>
#include "stringArray.h"

int main(void)
{
    stringArray_T s1 = malloc(sizeof(struct stringArray));
    s1->length=0;

    ReadStrings(s1, stdin);
    SortStrings(s1);
    WriteStrings(s1, stdout);

    free(s1);

    return 0;
}
