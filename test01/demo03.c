#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int add(int a,int b){
  return a+b;
}
int sub(int a,int b){
  return a-b;
}
int mul(int a,int b){
  return a*b;
}
int dev(int a,int b){
  return a/b;
}

int main(int argc, char const *argv[]){
    int (*pf)(int,int) = add; // 函数指针
    printf("%d\n", pf(1, 2)); // 调用函数指针指向的函数
    return 0;

}