#include <stdio.h>

int func()
{
    static int count = 0;
    printf("%d\n", count);
    return ++count && func();
}

int main()
{
    return func();
}
