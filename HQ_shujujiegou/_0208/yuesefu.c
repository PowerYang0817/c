#include<stdio.h>
#include<stdlib.h>
typedef struct PlayerList{
    int post;
    struct PlayerList *next;
}playerList_t;
void printList(playerList_t*head,int length);//打印
playerList_t* initList(int number){//初始化环
    playerList_t *head=(playerList_t*)malloc(sizeof(playerList_t));
    head->post=1;
    head->next=NULL;
    playerList_t *p=head;
    if(number<1){
        printf("参数错误\n");
        return NULL;
    }
    int i=2;
    while(i<=number){
        playerList_t *newNode=(playerList_t*)malloc(sizeof(playerList_t));
        newNode->post=i;
        newNode->next=NULL;
        p->next=newNode;
        p=p->next;
        i++;
    }
    p->next=head;//形成环
    return head;
}
playerList_t* delByNum(playerList_t *head,int start,int num,int length){
    playerList_t *p=head;
    playerList_t *show=head;
    while(start>1){
        p=p->next;//p指向start
        start--;
    }
    int count=1;
    while(p!=p->next){
        if(count==num){
            int flag=0;
            if(p->next==show){
                flag=1;
            }//美化
            printf("删除第%d个节点\n",p->post);
            playerList_t *temp=p->next;
            p->post=temp->post;
            p->next=temp->next;
            free(temp);
            if(flag){
                show=p;
            }//美化
            printList(show,--length);//美化
            count=1;
        }
        p=p->next;
        count++;
    }
    return p;
}
//约瑟夫问题,淘汰问题
void printList(playerList_t*head,int length){
    int num=length;
    while(num>0){
        printf("%d=>",head->post);
        head=head->next;
        num--;
    }
    printf("head\n");
}
int main(){
    printf("输入总个数-开始位置-跳跃位置");
    int n,start,num;
    scanf("%d%d%d",&n,&start,&num);
    if(num==1){
        printf("存活第%d个节点",n);
        return 0;
    }
    playerList_t *head=initList(n);
    printList(head,n);
    head=delByNum(head,start,num,n);
    free(head);
    return 0;
}