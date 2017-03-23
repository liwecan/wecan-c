#define MAX_NUM 256

struct stringArray{
    char strings[MAX_NUM];
    int length;
};

extern void ReadStrings(struct stringArray *s1, FILE *fp);
extern void WriteStrings(struct stringArray *s1, FILE *fp);
extern void SortStrings(struct stringArray *s1);
