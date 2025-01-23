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
    int (*p2)(int ,int) = sub;
    printf("%d\n", p2(1, 2));
    int (*p3)(int ,int) = mul;
    printf("%d\n", p3(1, 2));
    int (*p4)(int ,int) = dev;
    printf("%d\n", p4(1, 2));
    return 0;

}