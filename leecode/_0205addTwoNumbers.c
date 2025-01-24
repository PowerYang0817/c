#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)//两数相加
//笨蛋解法,新建一个链表,将两个链表的值相加,如果相加的值大于10,则将进位的值加到下一个链表中
//时间复杂度O(n),空间复杂度O(n)
{
    int num1=0,num2=0,n=0;
    struct ListNode *p1=l1,*p2=l2,*p3,*p4,*p5;
    p3=(struct ListNode *)malloc(sizeof(struct ListNode));
    p4=p3;
    p3->val=0;
    p3->next=NULL;
    while(p1!=NULL||p2!=NULL||n){
        if(p1&&p2){
            num1=p1->val+p2->val+n;
            n=num1/10;
            num1=num1%10;
            p4->val=num1;
            p4->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            p5=p4;
            p4=p4->next;
            p4->val=0;
            p4->next=NULL;
            p1=p1->next;
            p2=p2->next;
        }else if(p1){
            num1=p1->val+n;
            n=num1/10;
            num1=num1%10;
            p4->val=num1;
            p4->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            p5=p4;
            p4=p4->next;
            p4->val=0;
            p4->next=NULL;
            p1=p1->next; 
        }else if(p2){
            num1=p2->val+n;
            n=num1/10;
            num1=num1%10;
            p4->val=num1;
            p4->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            p5=p4;
            p4=p4->next;
            p4->val=0;
            p4->next=NULL;
            p2=p2->next;
        }else{//注意最后一位的进位
            p4->val=n;
            p4->next=NULL;
            return p3;
        }
    }
    p5->next=NULL; 
    return p3;
}
int main(int argc, char *argv[]){
    //官方解法，主体思路一致，但是代码更加简洁
    //如果两个链表的长度不同，则可以认为长度短的链表的后面有若干个 0 
    //int num1 = l1 ? l1->val : 0;      int num2 = l2 ? l2->val : 0;
    //无需区分某一链表为空的情况
    //进阶题：链表正向存储数字，如何相加
    //  ||
    //使用栈
}