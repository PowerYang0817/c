#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
typedef struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;//指向队尾
}queue_t,*lpqueue_t;
lpqueue_t initQueue(lpqueue_t q){//初始化队列
    q->front=-1;
    q->rear=-1;
}
int isEmpty(lpqueue_t p){
    return p->front==-1;
}
int isFull(lpqueue_t p){
    return p->front==(p->rear+1)%MAX_SIZE;
}
int insertQueue(lpqueue_t p,int value){//入队
    if(isFull(p)){
        printf("队列满，无法入队%d\n",value);
        return -1;
    }
    if(isEmpty(p)){
        p->front=0;
    }
    p->rear=(p->rear+1)%MAX_SIZE;//移动队尾
    p->data[p->rear]=value;
    return 0;
}
int outQueue(lpqueue_t p){//出队
    if(isEmpty(p)){
        printf("空队，无法出队");
        return -1;
    }
    if(p->front==p->rear){
        initQueue(p);
        return 0;
    }
    p->front=(p->front+1)%MAX_SIZE;//移动队首
    return 0;
}
int getLength(lpqueue_t p){//求队列长度
    if(isEmpty(p)){
        return 0;
    }
    if(p->rear>=p->front){
        return p->rear-p->front+1;
    }else{
        return p->rear-p->front+1+MAX_SIZE;
    }
}
int main(){
    lpqueue_t queue=initQueue((lpqueue_t)malloc(sizeof(queue_t)));
    insertQueue(queue,1);
    insertQueue(queue,2);
    insertQueue(queue,3);
    insertQueue(queue,4);
    insertQueue(queue,5);
    outQueue(queue);
    outQueue(queue);
    insertQueue(queue,6);
    insertQueue(queue,7);
    printf("size=%d\n",getLength(queue));
    for(int i=queue->front;i<queue->front+getLength(queue);i++){//打印队列
        printf("%d\n", queue->data[i%MAX_SIZE]);
    }
    free(queue);
}