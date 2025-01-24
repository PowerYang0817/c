#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return *(const char*)a - *(const char*)b; // 升序排序
}
bool CheckPermutation(char* s1, char* s2) {
    int ln1=0,ln2=0;
    ln1=strlen(s1);
    ln2=strlen(s2);
    printf("%d %d\n",ln1,ln2);
    qsort(s1,strlen(s1),sizeof(char),compare);
    qsort(s2,strlen(s2),sizeof(char),  compare);
    return strcmp(s1,s2);
}
int main(int argc, char* argv[]){
    char a[]="asdfg";
    char b[]="gfdsa";
    char c[]="sdalg";
    if(!CheckPermutation(a,b)){
        printf("%s\n","true");
    }else{
        printf("%s\n","false");
    }
    if(!CheckPermutation(a,c)){
        printf("%s\n","true");
    }else{
        printf("%s\n","false");
    }
}