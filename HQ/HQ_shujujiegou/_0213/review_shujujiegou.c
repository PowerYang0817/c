#include<stdlib.h>
#include<stdio.h>
//3
#if 0
#define MAX 20
typedef struct ArrList{
	int data[MAX];
    int length;
}arrList_t;
arrList_t * createLIst(){//创建顺序表
    arrList_t *table=(arrList_t*)malloc(sizeof(arrList_t));
    if(table==NULL){
        printf("err");
        return NULL;
    }
    table->length=0;
    return table;
}
int isFull(arrList_t *p){
    return p->length==MAX;
}
int insertNode(arrList_t *p,int value,int post){
    if(isFull(p)){
        return -1;
    }else if(post>=MAX||post<1){
        printf("postErr");
        return -1;
    }
    if(post>p->length){
        p->data[p->length]=value;
        p->length++;
        return 0;
    }
    for(int i=p->length;i>post-1;i--){
        p->data[i]=p->data[i-1];
    }
    p->data[post-1]=value;
    p->length++;
    return 0;
}
int delNode(arrList_t *p,int post){//删除
    if(post>p->length||post<1){
        printf("postErr\n");
        return -1;
    }
    for(int i=post-1;i<p->length-1;i++){
        p->data[i]=p->data[i+1];
    }
    p->length--;
    return 0;
}
void printArray(arrList_t *p) {//打印顺序表
    for (int i = 0; i < p->length; i++) {
        printf("%d ", p->data[i]);
    } 
    printf("\n");
}
#endif 
//6  链表
#if 0
typedef struct ListNode{
    int data;
    struct ListNode *next;
}listNode_t;
listNode_t * creatList(int value){//根节点创建
    listNode_t *head=(listNode_t *)malloc(sizeof(listNode_t));
    if(head==NULL){
        printf("failed\n");
        return NULL;
    }
    head->data=value;
    head->next=NULL;
    return head;
}
int getLength(listNode_t *head){//求长度
    int i=0;
    while(head!=NULL){
        head=head->next;
        i++;
    }
    return i;
}
listNode_t * insertNode(listNode_t *head,int value){//插入
    if(head==NULL){
        return creatList(value);
    }
    listNode_t *newNode=(listNode_t*)malloc(sizeof(listNode_t));
    if(newNode==NULL){
        printf("failed\n");
        return NULL;
    }
    newNode->data=value;
    newNode->next=NULL;
    listNode_t *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;
    return head;
}
listNode_t * delNode(listNode_t *head,int post){
    if(post<1||post>getLength(head)){
        printf("postERR\n");
        return head;
    }
    listNode_t *p=head;
    if(post==1){//删除第一个元素
        p=p->next;
        free(head);
        return p;
    }
    for(int i=2;i<post;i++){
        p=p->next;//删除节点前一个元素
    }
    listNode_t *temp=p->next;
    p->next=temp->next;
    free(temp);
    return head;
}
int findNode(listNode_t *head,int value){
    int post=0;
    while(head!=NULL){
        post++;
        if(head->data==value){
            return post;
        }
    }
    return -1;
}
void freeList(listNode_t *head){
    while(head!=NULL){
        listNode_t *temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
}
void printfList(listNode_t *head){//遍历
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    puts("NULL");
}
#endif
//8
#if 0
void reverse_list(list *p){// a b c null
    if(p==NULL){
        return;
    }
    reverse_list(p->next);
    printf("%d ",p->data);
}
#endif
//13
#if 1
#define MAX 20
typedef struct Stack{
    int data[MAX];
    int top;
}stack_t;
stack_t * creatStack(){
    stack_t *p=(stack_t*)malloc(sizeof(stack_t));
    if(p==NULL){
        printf("err\n");
        return NULL;
    }
    p->top=-1;
    return p;
}
int isEmpty(stack_t *p){
    return p->top==-1;
}
int isFull(stack_t *p){
    return p->top==MAX-1;
}
int push(stack_t*p,int value){//入
    if(isFull(p)){
        printf("stackFull\n");
        return -1;
    }
    p->top++;
    p->data[p->top]=value;
    return 0;
}
int pop(stack_t *p){//出
    if(isEmpty(p)){
        printf("stackEmpty\n");
        return -1;
    }
    int t=p->data[p->top];
    p->top--;
    return t;
}
void showStack(stack_t *p){
    if(isEmpty(p)){
        printf("Empty\n");
        return;
    }
    for (int i = p->top; i >= 0; i--) {
        printf("%d ", p->data[i]);
    }
}
//13
typedef struct Queue{
    int data[MAX];
    int front;
    int rear;
}queue_t;
void initQueue(queue_t*p){//初始化
    p->front=-1;
    p->rear=-1;
}
queue_t* creatQueue(){
    queue_t* p=(queue_t*)malloc(sizeof(queue_t));
    if(p==NULL){
        printf("err\n");
        return NULL;
    }
    initQueue(p);
    return p;
}
int isEmpty(queue_t *p){
    return p->front==-1;
}
int isFull(queue_t *p){
    return (p->rear+1)%MAX==p->front;
}
int getLength(queue_t *p){
    if(isEmpty(p)){
        return 0;
    }else if(isFull(p)){
        return MAX;
    }
    return (p->rear-p->front+MAX+1)%MAX;
}
void insertQueue(queue_t*p,int value){
    if(isFull(p)){
        printf("insert failed\n");
        return;
    }else if(isEmpty(p)){
        p->front=0;
    }
    p->rear=(p->rear+1)%MAX;
    p->data[p->rear]=value;
}
int outQueue(queue_t *p){
    if(isEmpty(p)){
        printf("queue Empty\n");   
        return -1;
    }
    if(p->front==p->rear){
        int n=p->data[p->front];
        initQueue(p);
        return n;
    }
    int n=p->data[p->front];
    p->front=(p->front+1+MAX)%MAX;
    return n;
}
#endif
 int main(int argc,char*argv[]){

    return 0;
 }