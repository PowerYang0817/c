#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define TABLE_SIZE 10
//size = n/α  α在0.7-0.8之间
typedef struct Node//哈希值
{
    int key;
    struct  Node*next;
}node_t;
typedef struct HashTable
{
    node_t **table;
}hashtable_t;
hashtable_t * createHash(){//创建一个空哈希表
    // node_t* node=(node_t*)malloc(sizeof(node_t));
    hashtable_t *hash=(hashtable_t*)malloc(sizeof(hashtable_t));//哈希表
    assert(hash);
    hash->table=(node_t**)malloc(sizeof(node_t*)*TABLE_SIZE);//哈希表内表赋空间
    assert(hash->table);
    //初始化
    for(int i=0;i<TABLE_SIZE;i++){
        hash->table[i]=NULL;
    }
    return hash;
}
int insertNode(hashtable_t *hash,int value){//插入
    node_t *newNode=(node_t*)malloc(sizeof(node_t));
    // assert(newNode);//在调试中使用
    if(newNode==NULL){
        printf("malloc failed\n");
        return -1;
    }
    int nkey=value%TABLE_SIZE;
    newNode->key=value;
    newNode->next=NULL;
    node_t *p=hash->table[nkey];
    if(hash->table[nkey]==NULL){//位置为空，直接给
        hash->table[nkey]=newNode;
        return 0;
    }
    while(p->next!=NULL){//p走到最后一个
        p=p->next;
    }
    p->next=newNode;
    return 0;
}
// 哈希表查找函数
int searchNode(hashtable_t *hash, int value) {
    int nkey = value % TABLE_SIZE;
    node_t *p = hash->table[nkey];
    while (p != NULL) {
        if (p->key == value) {
            return 1; // 找到目标值
        }
        p = p->next;
    }
    return 0; // 未找到目标值
}
// 哈希表释放函数
void freeHashTable(hashtable_t *hash) {
    if (hash == NULL) {
        return;
    }
    for (int i = 0; i < TABLE_SIZE; i++) {
        node_t *p = hash->table[i];
        while (p != NULL) {
            node_t *temp = p;
            p = p->next;
            free(temp);
        }
    }
    free(hash->table);
    free(hash);
}


int main(int argc, char const *argv[])
{
    hashtable_t *hash = createHash();
    insertNode(hash, 1);
    insertNode(hash, 11);
    insertNode(hash, 21);
    if (searchNode(hash, 11)) {
        printf("找到值 11\n");
    } else {
        printf("未找到值 11\n");
    }
    if (searchNode(hash, 22)) {
        printf("找到值 22\n");
    } else {
        printf("未找到值 22\n");
    }
    freeHashTable(hash);
    return 0;
}

