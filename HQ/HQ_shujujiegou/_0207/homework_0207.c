#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
typedef struct NameListNode{
    char name[20];
    struct NameListNode* next;
}NameListNode_t,*LpNameListNode_t;

LpNameListNode_t insertNodeinTail(LpNameListNode_t head,char *name){//尾部插入
    NameListNode_t *p=head;
    while(p->next!=NULL){
        p=p->next;
    }//找到最后一个节点
    LpNameListNode_t newNode=(LpNameListNode_t)malloc(sizeof(NameListNode_t));
    assert(newNode);//断言
    strcpy(newNode->name,name);
    newNode->next=NULL;
    p->next=newNode;
    return head;
}
void printList(LpNameListNode_t head){
    while(head!=NULL){
        printf("%s ",head->name);
        head=head->next;
    }
}
void freeList(LpNameListNode_t head){
    while(head!=NULL){
        LpNameListNode_t temp=head;
        head=head->next;
        free(temp);
    }
}
int main(){
    LpNameListNode_t head=(LpNameListNode_t)malloc(sizeof(NameListNode_t));
    assert(head);
    strcpy(head->name,"yang");
    head->next=NULL;
    insertNodeinTail(head,"li");
    insertNodeinTail(head,"liu");
    insertNodeinTail(head,"wang");
    printList(head);
    freeList(head);
    return 0;
}