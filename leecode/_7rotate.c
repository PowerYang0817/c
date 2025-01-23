#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
void rotate(int** matrix, int matrixSize, int* matrixColSize) {//旋转矩阵,思路为每次旋转四个位置
    int i,j;
    int n=matrixSize;
    int temp;
    for(i=0;i<n/2;i++){
        for(j=0;j<(n+1)/2;j++){
            temp=matrix[i][j];
            matrix[i][j]=matrix[n-1-j][i];
            matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
            matrix[j][n-1-i]=temp;
        }
    }
}
int main(int argc, char *argv[]){
    int a[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int b[][4]={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int c[][1]={{1}};
    int i,j;
    int n=3;
    int m=4;
    int p=1;
    int *matrixColSize=(int*)malloc(sizeof(int)*n);
    int **matrix=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        matrix[i]=(int*)malloc(sizeof(int)*n);
        matrixColSize[i]=n;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matrix[i][j]=a[i][j];
        }
    }
    rotate(matrix,n,matrixColSize);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    free(matrix);
    free(matrixColSize);
    return 0;

}