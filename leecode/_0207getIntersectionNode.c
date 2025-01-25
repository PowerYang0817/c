#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//判断两个链表是否相交
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }
    struct ListNode *pA = headA;
    struct ListNode *pB = headB;
    while (pA != pB){
        pA = pA == NULL ? headB : pA->next;//如果pA为空，那么pA指向headB，否则pA指向pA的下一个节点
        pB = pB == NULL ? headA : pB->next;//如果pB为空，那么pB指向headA，否则pB指向pB的下一个节点
    }
    return pA;
}
int main(int argc, char *argv[]){
    //官方题解：
    //时间复杂度为O(n)，空间复杂度为O(1)，可以使用双指针法
    //如果两个链表相交，那么两个链表的尾节点一定是相同的
    //为了解决两个链表长度不同，无法同时比较
    //但是a+b=b+a，长度相同，可以同时比较
    //a走到尾节点，再走b;b走到尾节点，再走a，这样就可以同时比较
    //如果两个链表不相交，那么a+b=b+a，最后都会走到NULL
    //如果两个链表相交，那么a+b=b+a，最后都会走到相交的节点

    //普通思路：
    //遍历链表A，将链表A的所有节点的地址存入哈希表
    //遍历链表B，判断链表B的节点的地址是否在哈希表中
    //如果在，那么链表A和链表B相交，返回链表B的节点的地址
    return 0;
}