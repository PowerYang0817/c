#include<stdio.h>
int main(int argc, char const *argv[]){
	int nums[10] = {1,2,3,4,5,6,7,8,9,10}; //定义数组
    int *p=nums; //定义指针
    int i;
    for(i=0;i<10;i++){
        printf("%d ",*(p+i)); //输出数组元素
    }
    int num[]={1,7,9}  ;
    int *q=num; //定义指针
    printf("\n%d ",*q++); //输出指针指向的变量的值
    printf("%d",*q++); //输出指针指向的变量的值
    return 0;
}