#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ListNode{
    int data;
    struct ListNode *next;
}ListNode_t;
// int  HashMap[4096]={0};
ListNode_t* creatList(int value){
    ListNode_t *head=(ListNode_t*)malloc(sizeof(ListNode_t));
    assert(head);//断言
    head->data=value;
    head->next=NULL;
    return head;
}
int lengthList(ListNode_t *head){
    ListNode_t *p=head;
    int ln=0;
    while(p!=NULL){
        ln++;
        p=p->next;
    }
    return ln;
}
int isEmpty(ListNode_t*head){
    return head==NULL;
}
ListNode_t* addInTail(ListNode_t *head,int value){
    ListNode_t *p=head;
    if(p==NULL){
        return creatList(value);//头为空，重新创建
    }
    while(p->next!=NULL){
        p=p->next;//走到尾部
    }
    ListNode_t *new=(ListNode_t*)malloc(sizeof(ListNode_t));
    assert(new);
    new->data=value;
    new->next=NULL;
    p->next=new;
    return head;
}
ListNode_t* addInPost(ListNode_t*head,int value,int post){
    if(post<1||post>lengthList(head)+1){
        printf("post不合法\n");
        return head;
    }
    ListNode_t *newNode=(ListNode_t *)malloc(sizeof(ListNode_t));
    assert(newNode);
    newNode->data=value;
    if(post==1){//特殊情况头节点
        newNode->next=head;
        return newNode;
    }
    ListNode_t *p=head;
    int i;
    for(i=1;i<post-1;i++){
        p=p->next;//p指向添加位置的前一个节点
    }
    newNode->next=p->next;
    p->next=newNode;
    return head;
}
int findByData(ListNode_t*head,int value){//查找指定元素
    ListNode_t *p=head;
    int index=1;
    while(p!=NULL){
        if(p->data==value){
            printf("在第%d个位置找到data=%d元素\n",index,value);
        }
        index++;
        p=p->next;
    }
}
ListNode_t* delListNode(ListNode_t *head,int value){//删除指定元素
    if(head->data==value){//删除头指针
        ListNode_t*temp=head->next;
        free(head);
        return temp;
    }
    ListNode_t *p=head->next;
    ListNode_t *pre=head;
    while(p!=NULL){
        if(p->data==value){
            pre->next=p->next;
            free(p);
            return head;
        }
        pre=p;
        p=p->next;
    }
    return head;
}
void freeList(ListNode_t **hd){//释放
    ListNode_t *head=*hd;
    while(head!=NULL){
        ListNode_t *temp =head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    *hd=NULL;
}
void printList(ListNode_t *head){//打印
    ListNode_t *p=head;
    while(p->next!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("%d\n",p->data);
}
int main(int argc,char*argv[]){
    ListNode_t *head=creatList(1);
    head=addInTail(head,2);
    head=addInTail(head,3);
    head=addInTail(head,4);
    printf("length=%d\n",lengthList(head));
    printList(head);

    head=delListNode(head,4);
    printList(head);

    head=addInPost(head,5,3);
    printList(head);
    head=addInPost(head,6,1);
    findByData(head,2);
    printList(head);


    freeList(&head);
    printf("isempty?%d\n",isEmpty(head));
    return 0;
}