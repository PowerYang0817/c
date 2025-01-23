#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int compare(const void* a, const void* b) {
    return *(const char*)a - *(const char*)b; // 升序排序
}
    
bool canPermutePalindrome(char* s) {//判断一个字符串能否重排为回文串
    qsort(s,strlen(s),sizeof(char),compare);
    // printf("%s\n",s);
    int i=0,n=0,num=0;
    char ch=*s;
    printf("%c\n",ch);
    for(i=0;i<strlen(s)+1;i++){
        if(ch==s[i]){
            n++;
        }else{
            if(n%2!=0){
                if(num==0){
                    num++;
                }else{
                    return false;
                }
            }
            n=1;
            ch=s[i];
        }
    }
    return true;
}
int main(int argc, char* argv[]){
    char a[]="co";
    char b[]="aabbgfg";
    printf("code:%d,aabbgfg:%d\n",canPermutePalindrome(a),canPermutePalindrome(b));
    // if(canPermutePalindrome(b)){
    //     printf("%s\n","true");
    // }else{
    //     printf("%s\n","false");
    // }
}