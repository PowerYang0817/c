//编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeDuplicateNodes(struct ListNode* head) {//移除未排序链表中的重复节点
    if(head==NULL){//空链表
        return NULL;
    }
    struct ListNode *p=head->next;
    struct ListNode *q=NULL;
    struct ListNode *t=head;
    while(p!=NULL){//遍历链表
        q=head;
        bool flag=true;
        while(q!=p){//遍历链表,如果有重复的,则删除
            if(q->val==p->val){
                flag=false;
                t->next=p->next;//删除
                free(p);
                p=t->next;//继续遍历
                break;
            }
            q=q->next;
        }
        if(flag){
            t=p;//t指向需要判断的节点
            p=p->next;//继续遍历    
        }
        
    }
    return head;
}
int main(int argc, char *argv[]){
    //优解：哈希表存储，时间复杂度O(n)，空间复杂度O(n)
    //我的解：时间复杂度O(n^2)，空间复杂度O(1)
    return 0;
}