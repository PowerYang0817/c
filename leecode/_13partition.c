#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x)//分隔链表,将小于x的节点放在前面，大于等于x的节点放在后面
{
    struct ListNode *p = head;
    struct ListNode *q = head;
    while (p!=NULL)
    {
        if (p->val < x){//如果小于x,则交换p和q的值
            int temp = p->val;
            p->val = q->val;
            q->val = temp;
            q = q->next;//q永远指向第一个大于等于x的节点
        }
        p = p->next;
    }
    return head;
}
struct ListNode *partition2(struct ListNode *head, int x){
    //既然操作时需要前一个节点，直接定义一个指向头指针的指针p，遍历时使用p->next，这样就不需要考虑头指针的问题了
    struct ListNode *list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    list1->next = NULL; // 初始化list1链表为空
    struct ListNode *list2 = (struct ListNode *)malloc(sizeof(struct ListNode));//大于x的节点链表的头指针
    list2->next = NULL; // 初始化list2链表为空

    struct ListNode *p = list1;
    p->next = head;
    struct ListNode *q = list2;
    while(p->next!=NULL){
        if(p->next->val>=x){
            q->next=p->next;
            q=q->next;
            p->next=p->next->next;//有危险，可能为空指针
        }else{
            p=p->next;
        }
    }
    q->next=NULL;
    p->next=list2->next;
    return list1->next;
}
struct ListNode* partition3(struct ListNode* head, int x) {//简单理解，双指针存储，LEETCODE官方题解
    // 创建两个虚拟头节点
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->next = NULL; // 初始化list1链表为空
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->next = NULL; // 初始化list2链表为空

    struct ListNode* p = list1; // p用于操作list1链表
    struct ListNode* q = list2; // q用于操作list2链表

    // 遍历原链表
    while (head != NULL) {
        if (head->val < x) {
            // 当前节点值小于x，移动到list1链表
            p->next = head;
            p = p->next;
        } else {
            // 当前节点值大于等于x，移动到list2链表
            q->next = head;
            q = q->next;
        }
        head = head->next; // 移动到下一个节点
    }
    // 拼接两个链表
    q->next = NULL; // 确保list2链表的末尾为NULL
    p->next = list2->next; // 将list2链表拼接到list1链表的末尾
    // 返回新的链表头节点
    struct ListNode* newHead = list1->next;
    free(list1); // 释放虚拟头节点list1
    free(list2); // 释放虚拟头节点list2
    return newHead;
}