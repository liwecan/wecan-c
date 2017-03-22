#include <stdio.h>
#include <time.h>

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct  timespec diff;
    if(t2.tv_nsec-t1.tv_nsec < 0){
        diff.tv_sec = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000; 
    } else {
        diff.tv_sec = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }

    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int funcA(int a, int b, int c, int d)
{
    return a+b+c+d;
}

int funcB(int a, int b, int c, int d, int e)
{
    return a+b+c+d+e;
}

int main(void)
{
    struct timespec start, end;
    double cpu_time1, cpu_time2;
    
    clock_gettime(CLOCK_REALTIME, &start);
    funcA(1,2,3,4);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    
    clock_gettime(CLOCK_REALTIME, &start);
    funcB(1,2,3,4,5);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time2 = diff_in_second(start, end);

    printf("time of funcA() : %lf sec\n", cpu_time1);
    printf("time of funcB() : %lf sec\n", cpu_time2);

    return 0;
}
