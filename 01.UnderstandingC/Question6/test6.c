#include <stdio.h>
#include <time.h>

#define TRY_NUM 1000000

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

int main(void)
{
    struct timespec start, end;
    double cpu_time1, cpu_time2, cpu_time3;
    
    clock_gettime(CLOCK_REALTIME, &start);
    for(int try=0; try<TRY_NUM; try++)
        funcA(1,2,3);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    
    clock_gettime(CLOCK_REALTIME, &start);
    for(int try=0; try<TRY_NUM; try++)
        funcB(1,2,3,4);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time2 = diff_in_second(start, end);

    clock_gettime(CLOCK_REALTIME, &start);
    for(int try=0; try<TRY_NUM; try++)
        funcC(1,2,3,4,5);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time3 = diff_in_second(start, end);


    printf("time of funcA(1,2,3    ) run %d times : %lf sec\n", TRY_NUM, cpu_time1);
    printf("time of funcB(1,2,3,4  ) run %d times : %lf sec\n", TRY_NUM, cpu_time2);
    printf("time of funcC(1,2,3,4,5) run %d times : %lf sec\n", TRY_NUM, cpu_time3);

    return 0;
}
