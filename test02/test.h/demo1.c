#include "factorial.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    int n;
    scanf("%d",&n);
    unsigned long long result = factorial(n);
    printf("%llu\n",result);
    return 0;
}