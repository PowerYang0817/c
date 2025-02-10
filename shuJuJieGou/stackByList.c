#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ListStack{//链栈,无头链表实现
    int data;
    struct ListStack  *next;
}listSatck_t,*lpListStack_t;
lpListStack_t initStack(){//初始化栈
    return NULL;
}
int isEmpty(lpListStack_t top){//是否为空
    return top==NULL;
}
lpListStack_t push(lpListStack_t top,int value){//入栈
    lpListStack_t newNode=(lpListStack_t)malloc(sizeof(listSatck_t));
    assert(newNode);
    newNode->data=value;
    newNode->next=top;

    top=newNode;//更新栈顶
    return top;
}
lpListStack_t pop(lpListStack_t top){//出栈
    if(isEmpty(top)){
        printf("栈空，无法出栈");
        return NULL;
    }
    lpListStack_t temp=top;//暂存栈顶
    top=top->next;
    free(temp);
    return top;
}
int getTop(lpListStack_t top){//获取栈顶元素
    if(isEmpty(top)){
        printf("栈空，无法出栈");
        return -1;
    }
    return top->data;
}
void destroyStack(lpListStack_t top) {//销毁
    lpListStack_t temp;
    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}
int main(){
    lpListStack_t stack=initStack();//
    stack=push(stack,1);
    stack=push(stack,2);
    stack=push(stack,3);
    printf("%d\n",getTop(stack));
    stack=pop(stack);
    printf("%d\n",getTop(stack));
    destroyStack(stack);
    return 0;
}