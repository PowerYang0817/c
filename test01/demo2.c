#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void print1(int a[][5],int n){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            printf("%d ",a[i][j]); //输出数组元素
        }
        printf("\n");
    }
}//比较数组指针和指针数组的输出结果
void print2(int (*a)[5],int n){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(*(a+i)+j)); //输出数组元素
        }
        printf("\n");
    }
}//比较数组指针和指针数组的输出结果
void print3(int (*a)[5],int n){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(*(a+i)+j)); //输出数组元素
        }
        printf("\n");
    }
}//比较数组指针和指针数组的输出结果
void print4(int a[][5],int n){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(a[i]+j)); //输出数组元素
        }
        printf("\n");
    }
}//比较数组指针和指针数组的输出结果
void print5(int *p[],int n){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(p[i]+j)); //输出数组元素
        }
        printf("\n");
    }
}//比较数组指针和指针数组的输出结果
void print6(int **p,int n){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            printf("%d ",*(*(p+i)+j)); //输出数组元素
        }
        printf("\n");
    }
}//比较数组指针和指针数组的输出结果
int main(int argc, char const *argv[]){
    int a[][5]={{1,2,3,4,5},{6,7,8,9,10}}; //定义二维数组
    int (*p1)[5]=a; //定义数组指针
    int *p2[2]={a[0],a[1]}; //定义指针数组

    print1(a,5); //输出数组元素
    print2(a,5);

    print3(p1,5);
    print4(p1,5);

    print5(p2,5);
    print6(p2,5);
    return 0;
}
