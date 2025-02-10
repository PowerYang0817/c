#include<stdio.h>
#include<time.h>
int main(int argc, char const *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    start=clock();
    printf("%d",2<<2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("程序运行时间：%.6f 秒\n", cpu_time_used);
    return 0;
}
