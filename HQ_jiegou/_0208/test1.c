#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode_t;
int main(){
    ListNode_t *head=(ListNode_t*)malloc(sizeof(ListNode_t));
    assert(head);
    head->next=NULL;
    ListNode_t *p=head;
//遍历有头
    while(p->next!=NULL){
        printf("%d",p->next->data);
        p=p->next;
    }
//无头
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
//清空(有头)
    while(p->next!=NULL){
        ListNode_t *temp=p->next;
        p->next=temp->next;
        free(temp);
        temp=NULL;
    }
//销毁
    while(p!=NULL){
        ListNode_t *temp=p;
        p=p->next;
        free(temp);
    }
    free(head);
}