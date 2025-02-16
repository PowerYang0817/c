#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void arrTorand(int *p, int length)//赋值随机数
{
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        p[i] = rand() % length + 1;
    }
}
int position(int*p,int left,int right){//分区
    int flag=p[right];
    while(left<right){
        while(p[left]<=flag&&left<right){
            left++;
        }
        p[right]=p[left];
        while(p[right]>=flag&&left<right){
            right--;
        }
        p[left]=p[right];
    }
    p[right]=flag;
    return right;
}
void quick_sort(int *p,int left,int right){
    if(left>=right){
        return;
    }
    int mid=position(p,left,right);
    quick_sort(p,left,mid-1);
    quick_sort(p,mid+1,right);
}
void printfArr(int *p, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", p[i]);
    }
    puts("");
}
int main(int argc, char const *argv[])
{
    int arr[20];
    arrTorand(arr,20);
    printfArr(arr,20);
    quick_sort(arr,0,19);
    printfArr(arr,20);
    return 0;
}
