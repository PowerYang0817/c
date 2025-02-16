#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct ListNode{
    int data;
    struct ListNode *next;
}listNode_t,*lpListNode_t;
lpListNode_t createList(int *arr,int length){//创建链表
    lpListNode_t head=(lpListNode_t)malloc(sizeof(listNode_t));//头
    lpListNode_t p=head;
    assert(head);
    head->data=*arr;
    head->next=NULL;
    if(length<1){
        printf("error");
        return NULL;
    }else if(length==1){
        return head;
    }
    int i;
    for(i=1;i<length;i++){
        lpListNode_t newNode=(lpListNode_t)malloc(sizeof(listNode_t));
        assert(newNode);
        newNode->next=NULL;
        newNode->data=*(arr+i);
        p->next=newNode;
        p=newNode;
    }
    return head;
}
void printList(lpListNode_t head){//打印 
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
void freeList(lpListNode_t head){//释放
    while(head!=NULL){
        lpListNode_t temp=head;
        head=head->next;
        free(temp);
    }
}
lpListNode_t mergeListAndList(lpListNode_t head1,lpListNode_t head2){
    lpListNode_t p=head1;
    lpListNode_t q=head2;
    lpListNode_t newHead=(lpListNode_t)malloc(sizeof(listNode_t));
    assert(newHead);
    lpListNode_t temp=newHead;
    while(p!=NULL&&q!=NULL){
        if((q->data)>(p->data)){//链表比较
            temp->next=p;
            temp=p;
            p=p->next;
        }else{
            temp->next=q;
            temp=q;
            q=q->next;
        }
    }
    if(p==NULL){//某个链表走到头，直接接另一个链表
        temp->next=q;
    }else if(q==NULL){
        temp->next=p;
    }
    lpListNode_t rt=newHead->next;
    free(newHead);
    return rt;
}
int main(){
    int a[]={1,3,4,6,7};
    int b[]={2,5,8,9};
    lpListNode_t p1=createList(a,sizeof(a)/4);
    lpListNode_t p2=createList(b,sizeof(b)/4);
    printList(p1);
    printList(p2);
    lpListNode_t head=mergeListAndList(p1,p2);
    printList(head);
    freeList(head);
    // freeList(p1);
    // freeList(p2);
    return 0;
}