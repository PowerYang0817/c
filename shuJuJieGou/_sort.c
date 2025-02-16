#include<stdio.h>
#include <stdlib.h>
void selectSort(int *p,int length){//选择排序
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(p[i]>p[j]){
                swap(p+i,p+j);
            }
        }
    }
}
//插入排序