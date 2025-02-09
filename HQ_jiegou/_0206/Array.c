#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct Array{
    int Arr[MAX];
    int length;
}ARRAY;
void initArray(ARRAY *arr) {
    arr->length = 0; 
}
void insertArray(ARRAY *arr, int index, int value) {
    if (arr->length >= MAX) {
        printf("数组已满，无法插入\n");
        return;
    }
    if (index < 0 || index > arr->length) {
        printf("索引越界，无法插入\n");
        return;
    }
    for (int i = arr->length - 1; i >= index; i--) {
        arr->Arr[i + 1] = arr->Arr[i];//将数组中index位置及以后的元素后移一位
    }
    arr->Arr[index] = value;
    arr->length++;
}
void deleteArray(ARRAY *arr, int index) {
    if (index < 0 || index >= arr->length) {
        printf("索引越界，无法删除\n");
        return;
    }
    for (int i = index; i < arr->length - 1; i++) {
        arr->Arr[i] = arr->Arr[i + 1];//将数组中index位置及以后的元素前移一位
    }
    arr->length--; 
}
void printArray(ARRAY *arr) {
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->Arr[i]);
    } 
    printf("\n");
}
int main(int argc, char *argv[]) {
    ARRAY arr;
    initArray(&arr);
    insertArray(&arr, 0, 1);
    insertArray(&arr, 1, 2);
    insertArray(&arr, 2, 3);
    insertArray(&arr, 3, 4);
    insertArray(&arr, 1, 5);
    printArray(&arr);
    deleteArray(&arr, 2);
    printArray(&arr);
    return 0;
}