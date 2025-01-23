#include <stdio.h>
#include <stdlib.h>
typedef enum week {
    mon =1, tue, wed, thu, fri, sat, sun
}week;
typedef struct today{
    int day;
    int month;
    int year;
    week *dayofweek;
}today;
int main(int argc, char* argv[]) {
    today today;
    today.dayofweek = (week*)malloc(sizeof(week));//先给指针分配内存，然后再给指针指向的内存分配内存
    scanf("%d%d%d%d",&today.day,&today.month,&today.year,today.dayofweek);
    printf("%d/%d/%d %d\n",today.day,today.month,today.year,*(today.dayofweek));
    free(today.dayofweek);
    return 0;
}