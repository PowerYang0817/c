#include<stdio.h>
#include<stdlib.h>
int findByValue(int *p,int length,int value){
    for(int i=0;i<length;i++){
        if(p[i]==value){
            return i;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int a[]={1,2,3,58,1,5,5,12,59,6512,965};
    int value=12;
    printf("%d at %d\n",value,findByValue(a,sizeof(a)/4,value));
    return 0;
}
