#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    
    FILE *fpa=fopen("D:/code/workespace vscode/IO/a.txt","r");
    if(fpa==NULL){
        perror("failed open\n");
        return -1;
    }
    FILE *fpb=fopen("D:/code/workespace vscode/IO/b.txt","w");
    if(fpb==NULL){
        perror("failed open\n");
        return -1;
    }
    //1
    char ch;
    while((ch=fgetc(fpa))!=EOF){
        fputc(ch,fpb);
    }
    //2
    char buf[20];
    while(fgets(buf,20,fpa)!=NULL){
        fputs(buf,fpb);
    }
    //3
    char buf[20];
    while(fread(buf,1,20,fpa)>0){
        fwrite(buf,1,strlen(buf),fpb);
        memset(buf,0,20);
    }
    fclose(fpa);
    fclose(fpb);
    return 0;
}
