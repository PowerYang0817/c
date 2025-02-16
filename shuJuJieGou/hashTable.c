#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
typedef struct pair{
    int key;
    char element[20];
}DATA,*LPDATA;
typedef struct hashTable{
    LPDATA * table;
    int size;//哈希表的大小,暂时设置为key%p
    int count;//哈希表中元素的个数
}HASH,*LPHASH;
LPHASH creatHashTable(int p){//创建哈希表,p为哈希表的大小(取余计算)
    LPHASH hash=(LPHASH)malloc(sizeof(HASH));
    assert(hash);//断言,判断是否分配成功
    hash->size=p;
    hash->table=(LPDATA*)malloc(sizeof(LPDATA)*hash->size);
    assert(hash->table);//断言,判断是否分配成功
    hash->count=0;
    int i;
    for(i=0;i<hash->size;i++){
        hash->table[i]=NULL;
    }//初始化哈希表
    return hash;
}
void insertData(LPHASH hash,LPDATA data){//使用的是开放寻址法处理冲突-线性探测
    int pos=(data->key)%(hash->size);//哈希地址 
    while(hash->table[pos]!=NULL){
        if(hash->table[pos]->key==data->key){//如果哈希地址不为空,并且key相同,则更新
            break;
        }    
        pos=(pos+1)%hash->size;
    }//解决哈希冲突,求出哈希地址
    if(hash->table[pos]==NULL){//如果哈希地址为空,则插入
        hash->table[pos]=data;
    }else{
        if(hash->table[pos]->key==data->key){//如果哈希地址不为空,并且key相同,则更新
            strcpy(hash->table[pos]->element,data->element);
        }else{
            printf("哈希表已满\n");   
        }
    }
}
void printHash(LPHASH hash){//打印哈希表
    int i;
    for(i=0;i<hash->size;i++){
        if(hash->table[i]!=NULL){
            printf("key:%d value:%s\n",hash->table[i]->key,hash->table[i]->element);
        }else{
            printf("key:%d value:NULL\n",i);
        }
    }
}
int main(int argc, char *argv[]){
    DATA data[5]={1,"白虎",11,"朱雀",2,"麒麟",16,"玄武",18,"青翼"};
    LPHASH hash=creatHashTable(10);//创建10个空间的哈希表
    int i;
    for(i=0;i<5;i++){
        insertData(hash,&data[i]);
    }
    printHash(hash);
    free(hash->table);
    free(hash);
    return 0;
}