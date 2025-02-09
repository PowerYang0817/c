#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *data;       // 动态数组存储栈的数据
    int capacity;    // 栈的最大容量
    int top;         // 栈顶指针，指向栈顶元素的位置
} Stack;
void initStack(Stack **stack, int capacity) {// 初始化栈,传入栈的容量
    *stack = (Stack *)malloc(sizeof(Stack));// 分配栈的内存空间
    (*stack)->data = (int *)malloc(capacity * sizeof(int));// 分配栈的数据数组的内存空间
    (*stack)->capacity = capacity;// 设置栈的容量
    (*stack)->top = -1;// 初始化栈顶指针为-1，表示栈为空
}
void push(Stack *stack, int value) {// 入栈操作
    if(stack->top == stack->capacity - 1) {
        printf("栈已满，无法入栈\n");
        return;
    }  
    stack->top++;
    stack->data[stack->top] = value;
}
void pop(Stack *stack) {// 出栈操作
    if(stack->top==-1){
        printf("栈为空，无法出栈\n");
    }
    printf("%d出栈\n",stack->data[stack->top]);
    stack->top--;
}
void peek(Stack *stack) {// 查看栈顶元素
    if(stack->top==-1){
        printf("栈为空，无法查看栈顶元素\n");
        return;
    }
    printf("栈顶元素为：%d\n",stack->data[stack->top]);
}
void isEmpty(Stack *stack) {// 判断栈是否为空
    if(stack->top==-1){
        printf("栈为空\n");
    }else{
        printf("栈不为空\n");
    }
}
void printStack(Stack *stack) {// 打印栈中元素
    if(stack->top==-1){
        printf("栈为空，无法打印\n");
        return;
    }
    printf("栈中元素为：");
    for(int i=stack->top;i>=0;i--){
        printf("%d ",stack->data[i]);
    }
    printf("\n");
}
void deleteStack(Stack *stack) {// 销毁栈
    free(stack->data);
    free(stack);
}
void decToBinBystack(int num){
    Stack *stack;
    initStack(&stack, 20);
    while(num>0){
        int n=num%2;
        push(stack,n);
        num=num/2;
    }
    printStack(stack);
    deleteStack(stack);
}
int main(int argc, char *argv[]) {
    decToBinBystack(14);
    return 0;
}