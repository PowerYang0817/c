#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    //思路为用两个数组记录行列是否有零,然后再遍历一遍矩阵,如果行列有零,则将该位置设为零
    int m=matrixSize;
    int n=*matrixColSize;
    int y[m];//记录行
    int x[n];//记录列
    memset(y,0,sizeof(y));
    memset(x,0,sizeof(x));
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(!matrix[i][j]){
                y[i]=x[j]=true;
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(y[i]||x[j]){
                matrix[i][j]=0;
            }
        }
    }
}
int main(int argc, char *argv[]){
    int arr[3][3]={{1,1,1},{1,0,1},{1,1,1}};
    int i,j;
    int matrixSize=3;
    int matrixColSize=3;
    int **matrix=(int**)malloc(sizeof(int*)*matrixSize);
    for(i=0;i<matrixSize;i++){
        matrix[i]=(int*)malloc(sizeof(int)*matrixColSize);
    }
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize;j++){
            matrix[i][j]=arr[i][j];
        }
    }
    setZeroes(matrix,matrixSize,&matrixColSize);
    for(i=0;i<matrixSize;i++){
        for(j=0;j<matrixColSize;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<matrixSize;i++){
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}