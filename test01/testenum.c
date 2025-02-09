#include <stdio.h>
#include <stdlib.h>

enum week {
    mon =1, tue, wed, thu, fri, sat, sun
};

int main(int argc, char* argv[]) {
    enum week today;
    //today = mon; // 假设今天是星期一
    scanf("%d", &today);
    switch (today) {
        case 1:
            printf("今天是星期一\n");
            break;
        case tue:
            printf("今天是星期二\n");
            break;
        case wed:
            printf("今天是星期三\n");
            break;
        case thu:
            printf("今天是星期四\n");
            break;
        case fri:
            printf("今天是星期五\n");
            break;
        case sat:
            printf("今天是星期六\n");
            break;
        case sun:
            printf("今天是星期日\n");
            break;
        default:
            printf("今天是周末\n");
    }
    return 0;
}
