#include<stdio.h>
#include<stdlib.h>
int rgb(char red, char green, char blue, char trans){//转16进制
    //0-3位存red...
    char map[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    char num[5]={red,green,blue,trans};
    int n=atoi(num),i=0;
    char n2[5];
    while(n>0){
        n2[i]=map[n%16];
        n=n/16;
        i++;
    }
    n2[i]='\0';
    printf("%s\n",n2);
}
int main(){
    rgb('1','2','3','4');
    
    // int a[10]={1,2,3,4,5};
    // int *p=a;
    // printf("%p\n",a);
    // printf("%p",((char*)p+1));
    return 0;
}