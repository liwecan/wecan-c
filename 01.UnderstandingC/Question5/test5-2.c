#include <stdio.h>

int func(int x)
{
    static int count = 0;
    printf("%d\n", count);
    return ++count && func(x++);
}

int main()
{
    return func(0);
}
