#define MAX_NUM 256

typedef struct stringArray{
    char strings[MAX_NUM];
    int length;
} *stringArray_T;

extern void ReadStrings(stringArray_T s1, FILE *fp);
extern void WriteStrings(stringArray_T s1, FILE *fp);
extern void SortStrings(stringArray_T s1);
