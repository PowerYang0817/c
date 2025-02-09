#include "factorial.h"
unsigned long long factorial(int n) {
    if (n < 0) {
        // 返回错误值，这里用ULLONG_MAX表示，也可以根据需要选择其他方式
        return (unsigned long long)-1; 
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
