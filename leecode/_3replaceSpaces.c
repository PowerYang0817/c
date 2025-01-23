#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* replaceSpaces(char* S, int length) {//替换空格为%20
    int i=0;
    int newlength=0;
    while(i<length){
        if(S[i]==' '){
            newlength+=2;
        }
        i++;
    }
    newlength+=length;
    printf("newlength:%d\n",newlength);
    char *p=(char*)malloc(sizeof(char)*newlength+1);
    char *q=p;
    for(i=0;i<length;i++){
        if(S[i]==' '){
            *p++='%';
            *p++='2';
            *p++='0';
        }else{
            *p++=S[i];
        }
    }
    *p='\0';//字符串结尾
    return q;
}
int main(int argc, char* argv[]){
    char a[]="We are happy."; 
    int length=13;
    char *p=replaceSpaces(a,length);
    printf("%s\n",p);  
    free(p);
    return 0;
}