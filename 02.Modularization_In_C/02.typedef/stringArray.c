#include <stdio.h>
#include <string.h>
#include "stringArray.h"

void ReadStrings(struct stringArray *s1, FILE *fp)
{
    fgets(s1->strings, MAX_NUM, fp);    
    s1->length = strlen(s1->strings) -1;

    printf("\ninput: %slength: %d\n\n", s1->strings, s1->length);
}

void WriteStrings(struct stringArray *s1, FILE *fp)
{
    fputs(s1->strings, fp);
}

void SortStrings(struct stringArray *s1)
{
    int i,j;
    for(i=0; i<s1->length; i++){
        for(j=i+1; j<s1->length; j++){
            if( strcmp(&(s1->strings[i]), &(s1->strings[j])) > 0) {
                s1->strings[i] = s1->strings[i] ^ s1->strings[j];
                s1->strings[j] = s1->strings[i] ^ s1->strings[j];
                s1->strings[i] = s1->strings[i] ^ s1->strings[j];
            }
        }
    }
}
