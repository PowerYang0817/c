#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isUnique(char* astr) {
    int a[26]={0};
    while(*astr++){
        if(a[*(astr-1)-'a']==0){
            a[*(astr-1)-'a']=1;//使用哈希表思路，将字符映射到数组中
        }else{
            return false;
        }
    }
    return true;
}//判断字符串中的字符是否唯一
int main(int argc, char* argv[]){
    #if 1
    char a[100]="asdfghjkl";
    char b[100]="leecode";
    if(isUnique(b)){
        printf("%s\n","true");
    }else{
        printf("%s\n","false");
    }
    #endif
    return 0;
}
