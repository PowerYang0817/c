#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 20
typedef struct {
    char name[20];
    int age;
    int score;
}student_t,*lpstudent_t;

typedef struct {
    student_t data[20];
    int length;
}seqlist_t,*lpseqlist_t;

lpseqlist_t createArray() {//创建顺序表
    lpseqlist_t arr = (lpseqlist_t)malloc(sizeof(seqlist_t));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }else{
        arr->length = 0;//初始化长度为0
        return arr;
    }
}
bool isEmpty(lpseqlist_t arr) {//判断顺序表是否为空
    return arr->length == 0;
}
bool isFull(lpseqlist_t arr) {//判断顺序表是否已满
    return arr->length == MAX;
}
void insertArray(lpseqlist_t arr,int post, student_t value) {//在顺序表中插入元素
   if(isFull(arr)){
        printf("顺序表已满，无法插入\n");
        return;
    } 
    if(post<1||post>MAX){
        printf("索引越界，无法插入\n");
        return; 
    }
    if(post>arr->length){
        arr->data[arr->length]=value;
        arr->length++;
        return; 
    }
    for(int i=arr->length-1;i>=post-1;i--){
        arr->data[i+1]=arr->data[i];//元素后移
    }
    arr->data[post-1]=value;
    arr->length++;
}
void deleteArray(lpseqlist_t arr,int post) {//删除顺序表中的元素
    if(isEmpty(arr)){
        printf("顺序表为空，无法删除\n");
        return;
    }
    if(post<1||post>arr->length){
        printf("索引越界，无法删除\n");
        return;
    }
    for(int i=post-1;i<arr->length-1;i++){
        arr->data[i]=arr->data[i+1];//元素前移 
    }
    arr->length--;
}
int lengthArray(lpseqlist_t arr) {//获取顺序表的长度
    return arr->length;
}
void printArray(lpseqlist_t arr) {//打印顺序表
    for(int i=0;i<arr->length;i++){
        printf("name=%s age=%d score=%d\n",arr->data[i].name,arr->data[i].age,arr->data[i].score);
    }
}
int findArrayByName(lpseqlist_t arr,char *name) {//根据姓名查找元素
    for(int i=0;i<arr->length;i++){
        if(strcmp(arr->data[i].name,name)==0){
            return i;
        }
    }
    return -1;
}
void clearArray(lpseqlist_t arr) {//清空顺序表
    arr->length=0;
}
int main(int argc, char *argv[]) {
    lpseqlist_t arr = createArray();
    student_t s1={"张一",20,100};
    student_t s2={"李二",21,99}; 
    student_t s3={"王三",22,98};
    student_t s4={"空四",23,97};
    student_t s5={"白五",24,96};
    insertArray(arr,1,s1);
    insertArray(arr,2,s2);
    insertArray(arr,2,s3);
    printf("1\n");
    printArray(arr);
    insertArray(arr,1,s4);
    insertArray(arr,10,s5);
    deleteArray(arr,2);
    printf("2\n");
    printArray(arr);
    printf("find李二=%d\n",findArrayByName(arr,"李二"));
    clearArray(arr);
    printf("length=%d\n",lengthArray(arr));
    free(arr);
    return 0;
}