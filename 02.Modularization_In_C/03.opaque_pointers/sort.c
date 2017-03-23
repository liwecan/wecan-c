#include <stdio.h>
#include "stringArray.h"

int main(void)
{
    stringArray_T s1 = NewStrings();

    ReadStrings(s1, stdin);
    SortStrings(s1);
    WriteStrings(s1, stdout);

    FreeStrings(s1);

    return 0;
}
