#include <stdio.h>
 struct ListNode
{
    int val;
    struct ListNode *next;
};
void deleteNode(struct ListNode *node)//删除链表中的节点
{
    struct ListNode *temp = node->next;
    node->val = node->next->val;//将下一个节点的值复制到当前节点
    node->next = node->next->next; //删除下一个节点
    free(temp);
}
int main(int argc, char *argv[]){
    //A B C D
    //A C C D
    //    X
    //A C D
    return 0;
}
