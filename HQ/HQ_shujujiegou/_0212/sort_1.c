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
void arrTorand(int *p, int length)//赋值随机数
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
void quickSort(int *p, int left, int right)
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
void bubbleSort(int *p, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (p[j] > p[j + 1])
            {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void selectSort(int *p,int length){//选择排序
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(p[i]>p[j]){
                swap(p+i,p+j);
            }
        }
    }
}
void insertSort(int *p,int length){//插入排序
    int i,j;
    for(i=1;i<length;i++){
        for(j=i;j>0;j--){
            if(p[j]<p[j-1]){
                swap(p+j,p+j-1);
            }else{
                break;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    //
    int length;
    scanf("%d", &length);
    int *arr = createArr(length);
    arrTorand(arr, length);//赋值随机数
    // printfArr(arr,length);
    // quickSort(arr, 0, length - 1); // 快速排序
    // bubbleSort(arr,length);//冒泡排序
    // selectSort(arr,length);//选择排序
    insertSort(arr,length);//插值排序
    printfArr(arr,length);
    free(arr);
    //
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("程序运行时间：%.6f 秒\n", cpu_time_used);
    return 0;
}
