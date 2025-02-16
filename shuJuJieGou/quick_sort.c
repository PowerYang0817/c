#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *createArr(int length)
{
    int *p = (int *)malloc(sizeof(int) * length);
    if (p == NULL)
    {
        printf("失败\n");
        return NULL;
    }
    return p;
}
void arrTorand(int *p, int length)
{
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        p[i] = rand() % length + 1;
    }
}
void swap(int *a, int *b)
{ // 交换
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *p, int left, int right)
{                       // 分半，返回中间值索引
    int mid = p[right]; // 设定最后一个值为比较值
    int i = left - 1;   // 小于mid部分的最后一位
    for (int j = left; j < right; j++)
    {
        if (p[j] < mid)
        {
            i++;
            swap(p + i, p + j);
        }
    }
    // 比较到最后一个，最后一个为基准值，放到中间
    swap(p + right, p + i + 1);
    return i + 1;
}
void quickSort(int *p, int left, int right)//快速排序
{
    if (left < right)
    {
        int mid = partition(p, left, right);
        quickSort(p, left, mid - 1);
        quickSort(p, mid + 1, right);
    }
}
void printfArr(int *p, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", p[i]);
    }
    puts("");
}
int compare(const void *a,const void *b){
    return (*(int *)a)-(*(int *)b);
}
int main(int argc, char const *argv[])
{
    int length;
    scanf("%d", &length);
    int *arr = createArr(length);
    arrTorand(arr, length);//随机数
    // printfArr(arr,length);
    // quickSort(arr, 0, length - 1); // 排序
    qsort(arr,length,sizeof(int),compare);
    printfArr(arr,length);
    free(arr);
    return 0;
}
