#include<stdio.h>
#include<string.h>
#include<ctype.h>
int xToDec(char *p){//16转10
    int len=strlen(p);
    int num=0,i=0;
    while(i<len){
        if(p[i]>=48&&p[i]<=57){
            num=num*16+(p[i]-48);
        }else{
            num=num*16+(p[i]-55);
        }
        i++;
    }
    return num;
}
void setbit3 (int *p){
    *p=*p|4;   //0100
}
void clearbit3(int *p){
    *p=*p&((1<<32)-5);    
}
char* partition(char *str){
    int n=0,m=0;
    int ln=strlen(str);
    // while(m<ln){
    //     if(str[m]>=97){
    //         char ch=str[m];
    //         str[m]=str[n];
    //         str[n]=ch;
    //         n++;
    //     }
    //     m++;
    // }//改变了大写字母的相对位置
    while(m<ln){
        if(islower(str[m])){
            char ch=str[m];
            for(int i=m;i>n;i--){
               str[i]=str[i-1];
            }
            str[n]=ch;
            n++;
        }
        m++;
    }
    return str;
}
int main(){ 
    char ch[]="1A";
    printf("%d\n",xToDec(ch));

    int num=10;
    setbit3(&num);
    printf("num=%d\n",num);
    clearbit3(&num);
    printf("num=%d\n",num);

    char str[]="anABerfCrDgc";
    partition(str);
    printf("%s\n",str);
}
