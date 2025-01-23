#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isFlipedString(char* s1, char* s2) {//判断是否为旋转字符串
    int len1=strlen(s1);
    int len2=strlen(s2);
    if(len1!=len2){
        return false;
    }
    char s[len1*2+1];
    strcpy(s,s2);
    strcat(s,s2);
    s[len1*2]='\0';
    printf("s=%s\n",s);
    return strstr(s,s1)!=NULL;
}
int main(int argc, char *argv[]){
    char a[]="waterbottle";
    char b[]="erbottlewat";
    printf("%d\n",isFlipedString(a,b));
    return 0;
    //xy yxyx
}