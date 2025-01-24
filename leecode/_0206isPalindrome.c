#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//  Definition for singly-linked list
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode *head)//反转链表
{
    struct ListNode *pre=NULL;
    while (head != NULL){
        struct ListNode *temp=head->next;
        head->next=pre;
        pre=head;
        head=temp;
    }
    return pre;
}
bool isPalindrome(struct ListNode *head)//判断链表是否为回文链表,使用快慢指针
{
    struct ListNode *slow=head;
    struct ListNode *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next; 
    }//快慢指针找到链表的中点
    struct ListNode *reverse=reverseList(slow);//反转链表
    struct ListNode *temp=reverse;
    while(temp!=NULL){
        if(head->val!=temp->val){
            return false;
        }
        head=head->next;
        temp=temp->next;
    }//比较链表的前半部分和后半部分
    //!注意：反转链表后，链表的后半部分会被反转，需要恢复链表
    reverseList(reverse);//恢复链表
    return true;
}
int main(int argc, char *argv[]){
    //官方题解：
    //将链表的值复制到数组中后用双指针法判断。
    // 也可以将链表的后半部分反转，然后将前半部分和后半部分进行比较
    
    //或者使用递归，递归可以实现从后往前遍历链表
    return 0;
}