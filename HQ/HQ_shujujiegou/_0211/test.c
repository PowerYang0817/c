#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}linkNode_t,*lpLinkNode_t;
lpLinkNode_t insertLinkNode(lpLinkNode_t head,int value){//尾插
    lpLinkNode_t p=head;
    lpLinkNode_t newNode=(lpLinkNode_t)malloc(sizeof(linkNode_t));
    assert(newNode);
    newNode->data=value;
    newNode->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;
    return head;
}
void delLink(lpLinkNode_t *head){//二级指针，直接修改头为NULL
    lpLinkNode_t h=*head;
    while(h!=NULL){
        lpLinkNode_t temp=head;
        h=h->next;
        free(temp);
    }
    *head=NULL;
}
#define MAX_SIZE 20
typedef struct {
    int data[MAX_SIZE];
    int top;
}stack_t;
int push(stack_t *p,int value){
    if(p->top==MAX_SIZE-1){
        printf("栈满\n");
        return -1;
    }
    p->data[++(p->top)]=value;
    return 0;
}
#define M 10
typedef struct {
    int data[M];
    int front;
    int rear;//指向最后一个元素，队列空时为-1
}queue_t,*lpqueue_t;
int isEmpty(lpqueue_t p){
    return p->front==-1;
}
int isFull(lpqueue_t p){
    return p->front==(p->rear+1)%M;
}
int getLength(lpqueue_t p){
    return (p->rear-p->front+1+M)%M==M;
}

int findByErFen(int *arr,int length,int value){//升序
    int left=0;
    int right=length-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(value==arr[mid]){
            return mid;
        }else if(value>arr[mid]){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}