#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void hannuo(int n,char a,char b,char c){ //a为起始柱，b为辅助柱，c为目标柱
    if(n==1){
        printf("%c-->%c\n",a,c);
    }else{
        hannuo(n-1,a,c,b);
        printf("%c-->%c\n",a,c);
        hannuo(n-1,b,a,c);
    }
}//汉诺塔问题(递归)
int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);
    hannuo(n,'A','B','C');
    return 0;
}