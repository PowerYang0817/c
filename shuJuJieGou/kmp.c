#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int *getNext(char *s){//获取next数组
    int len=strlen(s);
    int *next=(int*)malloc(sizeof(int)*len);
    int i=1;//当前位置
    int prefix_len=0;//当前相同前后缀长度
    next[0]=0;
    while(i<len){
        if(s[i]==s[prefix_len]){
            prefix_len++;
            next[i]=prefix_len;
            i++;
        }else{
            if(prefix_len==0){
                next[i]=0;
                i++;
            }else{//如果不相等,则回退
                prefix_len=next[prefix_len-1];//回退,直到找到相同的前缀
                //prefix_len既是当前相同前后缀长度,也是上一个相同前缀的下一个索引位置
            }   
        }
    }
    return next;
}
int kmp_search(char *string,char *pattern){
    int *next=getNext(pattern);
    int i=0;//字符串索引
    int j=0;//模式串索引
    int len=strlen(string);
    while(i<len){
        if(string[i]==pattern[j]){
            i++;
            j++;
        }else{
            if(j==0){
                i++;
            }else{
                j=next[j-1];//根据next数组,回退模式串
            }
        }
        if(j==strlen(pattern)){
            free(next);
            return i-j;
        }
    }
    free(next);
    return -1;
}
int main(int argc, char *argv[]){
    char a[]="hello";
    char b[]="ll";
    char c[]="aabaabcabciqbe";
    char d[]="abc";
    printf("%d\n",kmp_search(a,b));
    printf("%d\n",kmp_search(c,d));
    return 0;
}