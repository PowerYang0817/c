
#include "funlib.h"
userList * createUser(){//初始化用户
    userList *user1 = (userList *)malloc(sizeof(userList));
    strcpy(user1->uname, "admin");
    strcpy(user1->password, "123456");
    user1->bid = -1;
    userList *head=user1;
    //
    userList *user2 = (userList *)malloc(sizeof(userList));
    strcpy(user2->uname, "user");
    strcpy(user2->password, "123");
    user2->bid = 0;
    user2->next=NULL;
    head->next=user2;
    return head;
}
bookList * createBook(){//初始化书籍
    bookList *book1 = (bookList *)malloc(sizeof(bookList));
    bookList *head=book1;
    strcpy(book1->bname, "C");
    book1->bid = 1;
    strcpy(book1->author, "谭浩强");
    book1->price = 100;
    strcpy(book1->publish, "清华大学出版社");
    book1->state = 0;
    book1->next=NULL;
    //
    bookList *book2 = (bookList *)malloc(sizeof(bookList));
    strcpy(book2->bname, "数据结构");
    book2->bid = 2;
    strcpy(book2->author, "严蔚敏");
    book2->price = 80;
    strcpy(book2->publish, "清华大学出版社");
    book2->state = 0;
    book2->next=NULL;
    book1->next=book2;
    //
    bookList *book3 = (bookList *)malloc(sizeof(bookList));
    strcpy(book3->bname, "操作系统");
    book3->bid = 3;
    strcpy(book3->author, "汤小丹");
    book3->price = 90;
    strcpy(book3->publish, "清华大学出版社");
    book3->state = 0;
    book2->next=book3;
    book3->next=NULL;
    return head;
}
int login(userList *head,bookList *bookhead){//登录
    printf("欢迎使用图书管理系统\n1.登录\t2.注册\t3.退出\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            char uname[20];
            char password[20];
            printf("请输入用户名:");
            scanf("%s",uname);
            printf("请输入密码:");
            scanf("%s",password);
            userList *temp=head;
            while(temp!=NULL){
                if(strcmp(temp->uname,uname)==0&&strcmp(temp->password,password)==0){
                    printf("登录成功\n");
                    nowUser=temp;
                    return true;
                }
                temp=temp->next;
            }
            printf("登录失败\n");
            return false;
        case 2:
            // return register();
        case 3:
            printf("退出\n");
            freeList(head);
            freeBook(bookhead);
            exit(0);
            return false;
        default:
            printf("输入错误\n");
            return false;
    }
}
void showMenu(userList *userhead,bookList *bookhead){//菜单
    while(true){
        if(nowUser!=NULL||login(userhead,bookhead)){
            //登录成功
            if(nowUser->bid==-1){//管理员
                rootMenu(userhead,bookhead);
            }else{
                userMenu(userhead,bookhead);
            }
        }else{
            continue;
        }
        // puts("test");
        // int choice;
        // scanf("%d",&choice);
    }
}
void rootMenu(userList *userhead,bookList *bookhead){//管理员菜单
    printf("欢迎使用图书管理系统\n1.添加图书\t2.删除图书\t3.修改图书信息\t4.查询图书\t5.退出\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            addBook(bookhead);
            break;
        case 2:
            deleteBook(bookhead);
            break;
        case 3:
            updateBook(bookhead);
            break; 
        case 4:
            showBook(bookhead);
            break;
        case 5:
            printf("退出登录\n");
            nowUser=NULL;
            break;
        default:
            printf("输入错误\n");
            break;
    }
}
void userMenu(userList *userhead,bookList *bookhead){//用户菜单
    printf("欢迎使用图书管理系统\n1.查询图书\t2.借阅图书\t3.归还图书\t4.退出\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            showBook(bookhead);
            break;
        case 2:
            borrowBook(bookhead);
            break;
        case 3:
            returnBook(bookhead);
            break;
        case 4:
            printf("退出登录\n");
            nowUser=NULL;
            break; 
        default:
            printf("输入错误\n");
            break;
    }

}
void showBook(bookList *head){//打印图书信息
    bookList *temp=head;
    if(nowUser->bid==-1){//管理员
        while(temp!=NULL){
            printf("id:%d\t书名:%s\t作者:%s\t价格:%.2f\t出版社:%s\t状态(0未借出/1借出):%d\n",temp->bid,temp->bname,temp->author,temp->price,temp->publish,temp->state);
            temp=temp->next;
        }
    }else{
        while(temp!=NULL){
            if(temp->state==0){
                printf("书名:%s\t作者:%s\t价格:%.2f\t出版社:%s\n",temp->bname,temp->author,temp->price,temp->publish);
            }
            temp=temp->next;
        }
    }
}
void addBook(bookList *head){//添加图书
    printf("请输入id:");
    int bid;
    scanf("%d",&bid);
    printf("请输入书名:");
    char bname[50];
    scanf("%s",bname);
    printf("请输入作者:");
    char author[30];
    scanf("%s",author);
    printf("请输入价格:");
    float price;
    scanf("%f",&price);
    printf("请输入出版社:");
    char publish[100];
    scanf("%s",publish);
    bookList *temp=head;
    while(temp!=NULL){
        if(temp->bid==bid){
            printf("id已存在\n");
            return;
        }
        temp=temp->next; 
    }
    bookList *newBook=(bookList *)malloc(sizeof(bookList));
    newBook->bid=bid;
    strcpy(newBook->bname,bname);
    strcpy(newBook->author,author);
    newBook->price=price;
    strcpy(newBook->publish,publish);
    newBook->state=0;
    newBook->next=NULL;
    bookList *temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=newBook;
    printf("添加成功\n");
    showBook(head);
}
void deleteBook(bookList *head){//删除图书
    if(head->next==NULL){
        printf("只有一本图书，禁止删除\n");
        return;
    }
    printf("请输入id:");
    int bid;
    scanf("%d",&bid);
    bookList *temp=head;
    bookList *pre=NULL;
    while(temp!=NULL){
        if(temp->bid==bid){
            if(pre==NULL){
                head=temp->next; 
            }else{
                pre->next=temp->next;
            }
            printf("删除成功\n");
            showBook(head);
            return;
        }
        pre=temp;
        temp=temp->next;
    }
    printf("id不存在\n");
    showBook(head);
}
void updateBook(bookList *head){//修改图书信息
    printf("请输入id:");
    int bid;
    scanf("%d",&bid);
    printf("请输入书名:");
    char bname[50];
    scanf("%s",bname);
    printf("请输入作者:");
    char author[30];
    scanf("%s",author);
    printf("请输入价格:");
    float price;
    scanf("%f",&price);
    printf("请输入出版社:");
    char publish[100];
    scanf("%s",publish);
    bookList *temp=head;
    while(temp!=NULL){
        if(temp->bid==bid){
            strcpy(temp->bname,bname);
            strcpy(temp->author,author);
            temp->price=price;
            strcpy(temp->publish,publish);
            printf("修改成功\n");
            showBook(head);
            return; 
        } 
    }
    printf("id不存在\n");
    showBook(head);
}

void borrowBook(bookList *head){//借书
    if(nowUser->bid!=0){
        printf("您已经借阅了一本书\n");
        return;
    }else{
        showBook(head);
        printf("请输入书名:");
        char bname[50];
        scanf("%s",bname);
        bookList *temp=head;
        while(temp!=NULL){
            if(strcmp(temp->bname,bname)==0){
                if(temp->state==0){
                    temp->state=1;
                    nowUser->bid=temp->bid;
                    printf("借阅成功\n"); 
                    return;
                }else{
                    printf("该书已被借出\n");
                    return;
                }
            }
            temp=temp->next; 
        }
        printf("该书不存在\n");
        return;
    }
}
void returnBook(bookList *head){//还书
    if(nowUser->bid==0){
        printf("您没有借阅任何书\n");
        return; 
    }else{
        nowUser->bid=0;
        printf("归还成功\n");
        return;
    }
}
void freeList(userList *head){//释放链表
    userList *temp=head;
    while(temp!=NULL){
        userList *next=temp->next;
        free(temp);
        temp=next;
    }
}
void freeBook(bookList *head){//释放链表
    bookList *temp=head;
    while(temp!=NULL){
        bookList *next=temp->next;
        free(temp);
        temp=next;
    }
}