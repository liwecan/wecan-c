#include <stdio.h>

int func(int x)
{
    static int count = 0;
    int y = count;
    printf("%d\n", y);
    return ++count && func(x++);
}

int main()
{
    return func(0);
}
