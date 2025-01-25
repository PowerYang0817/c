#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct hashtable{
    struct ListNode *key;
    struct hashtable *next;
};

struct ListNode *detectCycle(struct ListNode *head)//判断链表是否有环
{
    struct ListNode *p=head;
    struct hashtable *hhead=(struct hashtable *)malloc(sizeof(struct hashtable));
    hhead->next=NULL;
    while(p!=NULL){
        struct hashtable *tem=hhead;
        while(tem!=NULL){//判断哈希表中是否有p
            if(tem->key==p){
                return p;
            }
            if(tem->next==NULL){
                struct hashtable *new=(struct hashtable *)malloc(sizeof(struct hashtable));
                new->key=p;
                new->next=NULL;
                tem->next=new;
                break;
            } 
            tem=tem->next;
        }
        p=p->next;
    }
    return NULL;
}
int main(int argc, char *argv[]){
    //上面是我的思路--哈希表-慢成乌龟啦！-使用时最好借助uthash库,将时间复杂度降到O(n)
    //官方题解：
    //时间复杂度为O(n)，空间复杂度为O(1)，可以使用双指针法
    //纯粹的数学公式：
    //使用快慢指针，快指针每次走2步，慢指针每次走1步
    //如果链表有环，那么快指针和慢指针一定会相遇
    //设链表中环外部分的长度为a,相遇点距离环的起点为b,距离环的终点为c
    //那么快指针走的距离为a+b+n(c+b),慢指针走的距离为a+b
    //因为快指针走的距离是慢指针的两倍，所以有a+b+n(c+b)=2(a+b)
    //化简得到a=(n-1)(c+b)+c
    //设置一个指针p指向链表的头节点，从快慢指针相遇的节点开始走，每次走1步
    //那么p走的距离为a时，慢指针走的距离为c
    //a与c差值为整圈数的距离，所以p和慢指针一定会相遇在环的起点
    //下面是代码实现：
    return 0;
}
struct ListNode* detectCycle2(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL) {
        slow = slow->next;
        if (fast->next == NULL) {
            return NULL;
        }
        fast = fast->next->next;
        if (fast == slow) {//如果有环，那么快指针和慢指针一定会相遇
            struct ListNode* ptr = head;//指针p开始行动
            while (ptr != slow) {//根据公式，p和慢指针一定会相遇在环的起点
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return NULL;
}