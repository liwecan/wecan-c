#include <stdio.h>

#define TEST() do{ a(); b(); c();}while(0)

void a(void){ printf("a\n"); }
void b(void){ printf("b\n"); }
void c(void){ printf("c\n"); }

int main(void)
{
    if(1)
        TEST();
    else
        printf("No Test");

    return 0;
}
