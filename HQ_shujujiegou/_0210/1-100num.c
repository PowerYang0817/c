#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sum(int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}
int main(){
    clock_t start, end;
    double cpu_time_used;
    start=clock();
//
    printf("%d",sum(10000));
//
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("程序运行时间：%.6f 秒\n", cpu_time_used);
    return 0;
}