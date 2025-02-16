#include<stdio.h>
#include<time.h>
#include<unistd.h>
typedef struct {
    int id;
    char name[20];
} Student;
int main(int argc, char const *argv[])
{
#if 0
    FILE *fp=fopen("D:/code/workespace vscode/IO/a.txt","w");
    if(fp==NULL){
        printf("打开失败\n");
        return 0;
    }
    fputc('h',fp);//单字符输入
    fputc('e',fp);
    fputc('l',fp);
    fputc('l',fp);
    fputc('o',fp);
    fputs("\nworld\n",fp);//字符串输出
    fclose(fp);
#endif 
#if 0
    fp=fopen("a.txt","r");
    char ch;
    while ((ch=fgetc(fp))!=EOF)//单字符输出
    {
        printf("%c",ch);
    }
#endif
#if 0
    fp=fopen("a.txt","wb");//二进制写,适合音乐，图片等内容
    if(fp==NULL){
        return -1;
    }
    Student s1={48,"小李"};
    Student s2={49,"小王"};
    fwrite(&s1,sizeof(Student),1,fp);//写入二进制数
    fwrite(&s2,sizeof(Student),1,fp);
#endif
#if 1
    FILE *fp=fopen("D:/code/workespace vscode/IO/a.txt","r");
    char a[10];
    while(fread(a,1,10,fp)>0){
        printf("%s\n",a);
    }
    // while(fgets(a,10,fp)!=NULL){
    //     printf("%s\n",a);
    // }
#endif
    fclose(fp);
    return 0;
}
