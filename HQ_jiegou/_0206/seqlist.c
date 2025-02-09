#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct {
    int Arr[MAX];
    int length;
}seqlist_t,*lpseqlist_t;
lpseqlist_t createArray() {//创建顺序表
    lpseqlist_t arr = (lpseqlist_t)malloc(sizeof(seqlist_t));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return NULL;
    }else{ 
        arr->length = 0;//初始化长度为0
        return arr;
    }
}
void insertArray(seqlist_t *arr, int post, int value) {//在顺序表中插入元素
    if (arr->length >= MAX) {
        printf("数组已满，无法插入\n");
        return;
    }else if (post < 1 || post > MAX) {
        printf("索引越界，无法插入\n");
        return;
    }
    if(post-1>=arr->length){
        arr->Arr[arr->length]=value;
        arr->length++;
        return;
    }
    for (int i = arr->length - 1; i >= post-1; i--) {
        arr->Arr[i + 1] = arr->Arr[i];//将数组中index位置及以后的元素后移一位
    }
    arr->Arr[post-1] = value;
    arr->length++;
}
void deleteArray(seqlist_t *arr, int post) {
    if (post < 1 || post > arr->length) {
        printf("索引越界，无法删除\n");
        return;
    }
    for (int i = post-1; i < arr->length - 1; i++) {
        arr->Arr[i] = arr->Arr[i + 1];//将数组中index位置及以后的元素前移一位
    }
    arr->length--; 
}
int findArray(seqlist_t *arr, int value) {//查找元素
    for(int i=0;i<arr->length;i++){
        if(arr->Arr[i]==value){
            return i;
        }
    }
}
void printArray(seqlist_t *arr) {//打印顺序表
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->Arr[i]);
    } 
    printf("\n");
}
int main(int argc, char *argv[]) {
    lpseqlist_t arr = createArray();
    insertArray(arr, 1, 1);
    insertArray(arr, 2, 2);
    insertArray(arr, 3, 3);
    insertArray(arr, 8, 4);
    insertArray(arr, 2, 5);
    printArray(arr);
    deleteArray(arr, 3);
    deleteArray(arr, 7);//越界
    printArray(arr);
    int index = findArray(arr, 3);
    printf("元素3的索引为：%d\n", index);
    free(arr);//释放内存
    return 0;
}