#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct stuListNode{
    int score;
    struct stuListNode *next;
}stuListNode_t;
stuListNode_t *stutail=NULL;//
stuListNode_t* insertStu(stuListNode_t *head,int val){
    if(stutail==NULL){
        stutail=head;
    }
    stuListNode_t *newNode=(stuListNode_t*)malloc(sizeof(stuListNode_t));
    newNode->score=val;
    newNode->next=NULL;
    stutail->next=newNode;//尾插
    stutail=newNode; 
}
void printList(stuListNode_t *head){
    while(head->next!=NULL){
        printf("%d->",head->next->score);
        head=head->next;
    }
    printf("NULL\n");
}
void freeList(stuListNode_t **hd){//释放
    stuListNode_t *head=*hd;
    while(head!=NULL){
        stuListNode_t *temp =head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    *hd=NULL;
}
int main(){
    stuListNode_t *head=(stuListNode_t*)malloc(sizeof(stuListNode_t));
    head->next=NULL;
    int val=0;
    while(1){
        scanf("%d",&val);
        if(val==-1){
            break;
        }
        insertStu(head,val);
    }
    printList(head);
    freeList(&head);
    return 0;
}