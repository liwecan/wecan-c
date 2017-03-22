#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>
#include <limits.h>
#include <stdint.h>

#define TRY_NUM 10000

static inline __attribute__((always_inline))
void get_cycles(unsigned *high, unsigned *low)
{
    asm volatile ("CPUID\n\t"
                  "RDTSC\n\t"
                  "mov %%edx, %0\n\t"
                  "movl %%eax, %1\n\t": "=r" (*high), "=r" (*low)::"%rax","%rbx","%rcx","%rdx"
                 );
}

static inline __attribute__((always_inline))
void get_cycles_end(unsigned *high, unsigned *low)
{
    asm volatile("RDTSCP\n\t"
                 "mov %%edx, %0\n\t"
                 "mov %%eax, %1\n\t"
                 "CPUID\n\t": "=r" (*high), "=r" (*low)::"%rax","%rbx","%rcx","%rdx"
                );
}

static inline __attribute__((always_inline))
uint64_t diff_in_cycles(unsigned high1, unsigned low1,
                        unsigned high2, unsigned low2)
{
    uint64_t start,end;
    start = (((uint64_t) high1 << 32) | low1);
    end = (((uint64_t) high2 << 32) | low2);
    return end - start;
}

int funcA(int a, int b, int c)
{
    return a+b+c;
}

int funcB(int a, int b, int c, int d)
{
    return a+b+c+d;
}

int funcC(int a, int b, int c, int d, int e)
{
    return a+b+c+d+e;
}

int main(int argc, char *argv[])
{
    uint64_t timec;
    unsigned timec_high1, timec_low1, timec_high2, timec_low2;

    timec = 0;
    get_cycles(&timec_high1, &timec_low1);
    for (int try = 0; try < TRY_NUM; try++)
    	funcA(1,2,3);
    get_cycles_end(&timec_high2, &timec_low2);
    timec = diff_in_cycles(timec_high1, timec_low1, timec_high2, timec_low2);
    printf("funcA(1,2,3    )(run %d times) executiom time : %lu cycles\n",TRY_NUM, timec);

	timec = 0;
    get_cycles(&timec_high1, &timec_low1);
    for (int try = 0; try < TRY_NUM; try++)
    	funcB(1,2,3,4);
    get_cycles_end(&timec_high2, &timec_low2);
    timec = diff_in_cycles(timec_high1, timec_low1, timec_high2, timec_low2);
    printf("funcB(1,2,3,4  )(run %d times) executiom time : %lu cycles\n",TRY_NUM, timec);

	timec = 0;
    get_cycles(&timec_high1, &timec_low1);
    for (int try = 0; try < TRY_NUM; try++)
    	funcC(1,2,3,4,5);
    get_cycles_end(&timec_high2, &timec_low2);
    timec = diff_in_cycles(timec_high1, timec_low1, timec_high2, timec_low2);
    printf("funcC(1,2,3,4,5)(run %d times) executiom time : %lu cycles\n",TRY_NUM, timec);    

    return 0;
}
