#include<stdio.h>
#include<string.h>
void reverseStr(int index,char *str){//字符串反序
    if(index==strlen(str));
    return;
    reverseStr(index+1,str);
    printf("%c",str[index]);
}
int fbList(int n){//求斐波那契数列第n项值
    if(n==0||n==1)
    return 1;
    return fbList(n-1)+fbList(n-2);
}
int main(int argc,char *argv[]){
    char a[]="abcdefg";
    reverseStr(0,a);
    printf("%d",fbList(6));
    return 0;
}