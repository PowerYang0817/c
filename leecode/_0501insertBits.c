#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* dectobin(int n){//转二进制
    char *str=(char*)malloc(sizeof(char)*32);
    int i=0;
    while(n!=0){
        str[i]=n%2+'0';
        n/=2;
        i++;
    }
    str[i]='\0';
    // for(int j=0;j<i/2;j++){
    //     char temp=str[j];
    //     str[j]=str[i-j-1];
    //     str[i-j-1]=temp; 
    // }//是否换为正向
    return str;
}
int insertBits(int N, int M, int i, int j) {//在n的i-j处替换为m
    char *pN=dectobin(N);
    char *pM=dectobin(M);
    int lenN=strlen(pN);
    int lenM=strlen(pM);
    if(lenM>j-i+1){
        //printf("M的长度大于j-i+1，无法插入\n");
        return 0;
    }
    for(int k=0;k<j-i+1;k++){
        if(k<lenM){
            pN[i+k]=pM[k]; 
        }else{
            pN[i+k]='0';
        }
    }
    printf("%d\n",lenN);
    printf("%s\n",pN);
    printf("pN[0]=%d\n",pN[0]-48);
    //字符串转数字
    int num=0;
    for(int i=lenN-1;i>=0;i--){
        num=num*2+pN[i]-48;
    }
    return num;
}
int insertBits(int N, int M, int i, int j){//位运算写法

}
int main(int argc, char *argv[]) {
    printf("%d\n",insertBits(1024,19,2,6));
    //很愚蠢，利用好位运算去计算，我的方法无法实现一些特殊情况，比如m位数<n位数时
    return 0;
}