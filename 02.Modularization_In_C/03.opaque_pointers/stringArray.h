#define MAX_NUM 256

typedef struct stringArray *stringArray_T;

extern stringArray_T NewStrings(void);
extern void FreeStrings(stringArray_T s1);

extern void ReadStrings(stringArray_T s1, FILE *fp);
extern void WriteStrings(stringArray_T s1, FILE *fp);
extern void SortStrings(stringArray_T s1);
