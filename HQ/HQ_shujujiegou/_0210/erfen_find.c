#include<stdio.h>
#include<stdlib.h>
int findByValue(int *p,int left,int right,int value){//二分查找，升序排列
    while(left<=right){
        int mid=left+(right-left)/2;//中间值
        if(value==p[mid]){
            return mid;
        }else if(value>p[mid]){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int a[]={1,2,3,5,9,11,15,26,48,59,95,100};
    //       0,1,2,3,4, 5, 6, 7, 8, 9,10,11
    int value=59;
    printf("%d at %d",value,findByValue(a,0,sizeof(a)/4-1,value));
    return 0;
}
