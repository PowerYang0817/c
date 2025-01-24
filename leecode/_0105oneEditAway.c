#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool oneEditAway(char *first, char *second)
{ // 判断是否一次编辑
    int len1 = strlen(first);
    int len2 = strlen(second);
    if (abs(len1 - len2) > 1)
    {
        return false;
    }
    int i = 0, j = 0, flag = 0;
    while (i < len1 && j < len2)
    {
        if (*(first + i) != *(second + j))
        {
            flag++;
            if (len1 == len2)
            {
                i++;
                j++;
            }// 长度相等，同时移动两个指针
            else if (len1 > len2)
            {
                i++;
            }// 长度不相等，移动长的字符串指针
            else
            {
                j++;
            }
        }
        else
        {
            i++;
            j++;
        }
    }
    return flag <= 1;// 最多只能有一次编辑
}
int main(int argc, char *argv[])
{
    char a[] = "teacher";
    char b[] = "bleacher";
    char c[] = "mart";
    char d[] = "kmart";
    printf("pale,ple:%d\n",oneEditAway(a,b));
    printf("mart,karma:%d\n",oneEditAway(c,d));
    // printf("pale,ple:%d\n", oneEditAway2(a, b));
    // printf("mart,karma:%d\n", oneEditAway2(c, d));
}