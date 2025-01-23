#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* compressString(char* S){//压缩字符串，如果压缩后的字符串没有变短，则返回原先的字符串
    int len=strlen(S);
    int i=0,j=0,n=0,k,ln;
    char num[6];
    char chs[50000]={0};
    char ch=*S;
    for(i=0;i<len;i++){
        if(ch==S[i]){
            n++;
        }else{
            sprintf(num,"%d",n);//将数字转换为字符串
            chs[j++]=ch;
            ln=strlen(num);
            for(int k=0;k<ln;k++){
                chs[j++]=num[k];
            }
            n=1;
            ch=S[i];
        }
    }
    sprintf(num,"%d",n);
    chs[j++]=ch;
    ln=strlen(num);
    for(int k=0;k<ln;k++){
        chs[j++]=num[k];
    }
    chs[j]='\0';
    printf("chs=%s\n",chs);
    if(strlen(chs)>=len){
        return S;
    }else{
        strcpy(S,chs);
        return S;
    }
}
int main(int argc, char* argv[]){
    char a[]="aabcccccaaa";
    char b[]="abbccd";
    char c[]="";
    char d[]="a";
    char e[]="abcccccccccc";
    printf("%s\n",compressString(a));
    printf("%s\n",compressString(b));
    printf("%s\n",compressString(c));
    printf("%s\n",compressString(d));
    printf("%s\n",compressString(e));

}