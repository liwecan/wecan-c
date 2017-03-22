#include <stdio.h>

int r1(int i, int N)
{
    return (i<N && printf("%d\n", i) && !r1(i+1, N)) || printf("%d\n", i);
}

int r2(int i, int N)
{
    return (printf("%d\n", i) && i<N && !r2(i+1, N)) || printf("%d\n", i); 
}

int r3(int i, int N)
{
    return (i<N && printf("%d\n", i) && r3(i+1, N)) || printf("%d\n", i); 
}

int main(int argc, char *argv[])
{
    printf("test r1\n");
    r1(1,3);
    printf("\ntest r2\n");
    r2(1,3);
    printf("\ntest r3\n");
    r3(1,3);

    return 0;
}
