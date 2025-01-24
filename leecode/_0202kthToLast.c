#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 int kthToLast(struct ListNode* head, int k) {//返回链表倒数第k个节点的值
    int len=0;
    struct ListNode *p=head;
    struct ListNode *q=head;
    while(p->next!=NULL){
        len++;
        p=p->next;
        if(len>=k){//p指针和q指针相距k个节点，当p指针到达链表尾部时，q指针刚好到达倒数第k个节点。
            q=q->next;
        }
    }
    return q->val;
}
int main(int argc, char *argv[]){
    //较佳解法：双指针，时间复杂度O(n)，空间复杂度O(1)
    //两个指针p和q，p指针先走k步，然后p和q指针一起走，当p指针到达链表尾部时，q指针刚好到达倒数第k个节点。
    return 0;
}
