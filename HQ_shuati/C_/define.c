#include<stdio.h>
//交换
#define CHANGE(x,y) do{ \ 
x=x+y;\
y=x-y;\
x=x-y;\
}while(0);
#define MIN(x,y) (x)>(y)?(y):(x)
int main(){
    int a=1;
    int b=2;
    CHANGE(a,b);
    printf("%d %d",a,b);
}