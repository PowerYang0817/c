#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    // FILE *fpa=fopen("D:/code/workespace vscode/IO/a.txt","r");
    // if(fpa==NULL){
    //     perror("failed open\n");
    //     return -1;
    // }
    //1 求行数
    // char ch;
    // int ln=0;
    // while((ch=fgetc(fpa))!=EOF){
    //     if(ch=='\n'){
    //         ln++;
    //     }
    // }
    // printf("有%d行",ln+1);
    // //2求行数
    // int ln=0;
    // char buf[10];
    // while(fgets(buf,10,fpa)!=NULL){
    //     if(buf[strlen(buf)-1]=='\n')
    //     ln++;
    // }
    // printf("有%d行",ln+1);
    //3 统计文件大小
    FILE *fpa=fopen("D:/code/workespace vscode/IO/a.txt","rb");//window中\n->\r\n,两个字符
    //需要以二进制命令打开
    if(fpa==NULL){
        perror("failed open\n");
        return -1;
    }
    int num=0;
    while(fgetc(fpa)!=EOF){
        num++;
    }
    printf("%d字节\n",num);
    fseek(fpa,0,SEEK_SET);
    //4 统计文件大小
    char buf[10];
    int n;
    num=0;
    while((n=fread(buf,1,10,fpa))>0){
        num+=n;
    }
    printf("%d字节\n",num);
    fseek(fpa,0,SEEK_SET);
    //5 统计大小
    fseek(fpa,0,SEEK_END);
    printf("%d字节\n",ftell(fpa));
    fclose(fpa);
    return 0;
}
