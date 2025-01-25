#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "uthash.h"
//需要引入uthash.h头文件
typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;
void printHashTable(HashItem *hashTable){//打印哈希表
    HashItem *item = NULL;
    for (item = hashTable; item != NULL; item = item->hh.next){
        printf("key: %d, val: %d\n", item->key, item->val);
    } 
}
void addHashTable(HashItem **hashTable, int key, int val){//添加哈希表
    HashItem *item = NULL;
    item = malloc(sizeof(HashItem));
    item->key = key;
    item->val = val;
    HASH_ADD_INT(*hashTable, key, item);//添加哈希表,第一个参数为哈希表，第二个参数为哈希表的键，第三个参数为哈希表的元素
}
void freeHashTable(HashItem *hashTable){//释放哈希表
    HashItem *item = NULL;
    HashItem *tmp = NULL;
    HASH_ITER(hh, hashTable, item, tmp){//遍历哈希表,第一个参数为哈希表，第二个参数为哈希表的元素，第三个参数为哈希表的元素的指针，第四个参数为哈希表的元素的指针的指针
        HASH_DEL(hashTable, item);//删除哈希表,第一个参数为哈希表，第二个参数为哈希表的元素
        free(item);
    }
}
int main(int argc, char *argv[]){
    HashItem *hashTable = NULL;
    addHashTable(&hashTable, 1, 1);
    addHashTable(&hashTable, 2, 2);
    addHashTable(&hashTable, 3, 3);
    addHashTable(&hashTable, 4, 4);
    printHashTable(hashTable);
    HashItem *find = NULL;
    int key = 1;
    HASH_FIND_INT(hashTable, &key, find);//查找哈希表,find为找到的元素的指针
    if (find != NULL){
        printf("find key: %d, val: %d\n", find->key, find->val); 
    }
    freeHashTable(hashTable);
    return 0;
}
