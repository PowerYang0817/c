#include<stdio.h>
#include<time.h>
typedef union 
{
    int size;
    char anme[20];
    double period ;
    /* data */
}bg;

int main(int argc, char const *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    start=clock();
    printf("%d",sizeof(bg));



    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("程序运行时间：%.6f 秒\n", cpu_time_used);
    return 0;
}
