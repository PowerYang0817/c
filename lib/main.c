#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
    int bid;
    char bname[50];
    char author[30]; // 作者
    float price;
    char publish[100]; // 出版社
    int state;         // 1  0未借出
} book;
typedef struct
{
    char uname[20];
    char password[30];
    int bid; //  -1  0未 或Book编号
} user;
char now_uname[20];
// book books[100]; //books 结构体数组名
// user users[5];//users 结构体数组名
book books[100] = {{1, "c语言程序设计", "谭浩强", 50.0, "清华大学出版社", 0},
                   {2, "数据结构", "严蔚敏", 60.0, "清华大学出版社", 0},
                   {3, "java程序设计", "明日科技", 40.0, "人民邮电出版社", 0}};
user users[5] = {{"admin", "123456", -1},
                 {"rose", "123", 0}};
int bookln = 3;
user now_user;

void initMenu();  // 初始化菜单
void showUser();  // 普通用户菜单
void showAdmin(); // 管理员菜单

void showAdminMenu(); // 管理员功能
void showUserMenu();  // 用户功能

user *login(); // 登录

void addBook();    // 增加图书
void delBook();    // 删除图书
void updateBook(); // 更新图书

void adminshowBook(); // 查找图书

void borrowBook(); // 借阅图书
void returnBook(); // 归还图书

int main(int argc, char *argv[])
{
    int func = 1;
    while (func)
    {
        // 输出页面
        // 登录页面
        initMenu();
        user *p = login(); // 登录函数返回值
        if (p == NULL)
        {
            continue;
        }
        now_user = *p;
        if (p == NULL)
        {
            printf("登录失败\n");
        }
        else
        {
            int user = p->bid; // 登陆函数返回值
            if (user == -1)
            {
                showAdminMenu();
                continue;
                func = 0;
            }
            else
            {
                showUserMenu();
                continue;
                func = 0;
            }
        }
    }
    // 结束
    printf("程序结束\n");
}
void initMenu()
{ // 初始化菜单
    // system("cls");
    printf("-----------------------------\n");
    printf("|       欢迎来到图书馆　　　|\n");
    printf("|                     　　　|\n");
    printf("-----------------------------\n");
}
void showUser()
{
    printf("\n*********************************************\n");
    printf("*********欢迎来到Ｔｉｎａ书店****************\n");
    printf("-----1.借书---2.还书---3.查看全部书籍----４.退出-\n");
    printf("请选择：");
} // 普通用户菜单
void showAdmin()
{
    printf("\n**************************************************\n");
    printf("**************欢迎来到Ｔｉｎａ书店****************\n");
    printf("1.添加书籍 2.删除书籍 3.修改书籍 4.查看书籍 5.退出\n");
    printf("请选择：");
}
void showAdminMenu()
{ // 管理员菜单
    int temp = 1;
    while (temp)
    {
        initMenu();
        showAdmin();
        int func;
        printf("请选择功能：\n");
        scanf("%d", &func);
        switch (func)
        {
        case 1:
            // 增加图书
            addBook();
            break;
        case 2:
            // 删除图书
            delBook();
            break;
        case 3:
            // 修改图书
            updateBook();
            break;
        case 4:
            // 显示所有图书
            adminshowBook();
            break;
        case 5:
            // 退出
            temp = 0;
            break;
        default:
            printf("输入错误\n");
            break;
        }
    }
};
void showUserMenu()
{ // 用户菜单

    int func;
    int temp = 1;
    while (temp)
    {
        initMenu();
        showUser();
        printf("请选择功能：\n");
        scanf("%d", &func);
        switch (func)
        {
        case 1:
            // 借阅图书
            borrowBook();
            break;
        case 2:
            // 归还图书
            // returnBook();
            returnBook();
            break;
        case 3:
            // 显示所有图书
            adminshowBook();
            break;
        case 4:
            // 退出
            temp = 0;
            break;
        default:
            printf("输入错误\n");
            break;
        }
    }
}
user *login() // 登录
{
    printf("-------1.登录　　2.退出------\n");
    printf("请选择：");
    int x;
    scanf("%d", &x);
    if (x == 2)
    {
        exit(0);
    }
    else
    {
        char uname[20];
        char passwd[30];
        int i = 0;
        printf("请输入账号\n");
        scanf("%s", uname);
        printf("请输入密码\n");
        scanf("%s", passwd);
        for (i = 0; i < 5; i++)
        {
            // 判断身份bid 为 1:管理员　2:普通用户　0:登录失败
            if (strcmp(uname, users[i].uname) == 0 && strcmp(passwd, users[i].password) == 0)
            // if(uname == users[i].name && passwd == users[i].password)
            {
                if (users[i].bid == -1)
                {
                    // 进入管理员页面；
                    //printf("1\n");
                    return &users[i];
                }
                else if (users[i].bid == 0)
                {
                    // 进入未借书页面
                    //printf("2\n");
                    return &users[i];
                }
            }
        }
        printf("账号密码错误\n");
        return NULL;
    }
}
void addBook()
{ // 增加图书
    int i = 0, flag = 0;
    int id = 0;
    printf("请输入要添加的书籍编号\n");
    scanf("%d", &id);
    for (i = 0; i < bookln; i++)
    {
        if (books[i].bid == id)
        {
            printf("书籍存在\n");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("请输入要添加的书籍信息:ID 书名 作者 价格 出版社 状态\n");
        scanf("%d%s%s%f%s%d", &books[bookln].bid, books[bookln].bname, books[bookln].author, &books[bookln].price, books[bookln].publish, &books[bookln].state);
        bookln++;
    }
} // 增加图书
void delBook()
{
    int i = 0, flag = 0, t = 0;
    int id = 0;
    printf("请输入要删除的书籍编号\n");
    scanf("%d", &id);
    for (i = 0; i < bookln; i++)
    {
        if (books[i].bid == id)
        {
            printf("成功删除\n");
            flag = 1;
            t = i;
            break;
        }
    }
    int j = 0;
    if (flag == 1)
    {
        for (j = t; j < bookln; j++)
        {
            books[j].bid = books[j + 1].bid;
            // books[j].bname=books[j+1].bname;
            strcpy(books[j].bname, books[j + 1].bname);
            // books[j].author=books[j+1].author;
            strcpy(books[j].author, books[j + 1].author);
            books[j].price = books[j + 1].price;
            // books[j].publish=books[j+1].publish;
            strcpy(books[j].publish, books[j + 1].publish);
            books[j].state = books[j + 1].state;
        }
    }
    bookln--;

} // 删除图书
void adminshowBook()
{
    int i = 0;
    for (i = 0; i < bookln; i++)
    {
        printf("书籍编号:%d  书名:%s  作者:%s  价格:%f \n出版社:%s  书籍状态:%d \n\n", books[i].bid, books[i].bname, books[i].author, books[i].price, books[i].publish, books[i].state);
    }
}
void updateBook()
{ // 更新图书
    int i = 0, flag = 0, t = 0;
    int id = 0;
    printf("请输入要修改的书籍编号\n");
    scanf("%d", &id);
    for (i = 0; i < bookln; i++)
    {
        if (books[i].bid == id)
        {
            printf("书籍存在\n");
            flag = 1;
            t = i;
            break;
        }
    }
    if (flag == 1)
    {
        int bid2;
        char bname2[50];
        char author2[30];
        float price2;
        char publish2[100];
        int state2;
        printf("请输入要修改的书籍信息\n");
        scanf("%d%s%s%f%s%d", &bid2, bname2, author2, &price2, publish2, &state2);
        // scanf("%s%s%f%s",books[bookln].bname,books[bookln].author,&books[bookln].price,books[bookln].publish);
        books[t].bid = bid2;
        strcpy(books[t].bname, bname2);
        strcpy(books[t].author, author2);
        books[t].price = price2;
        strcpy(books[t].publish, publish2);
        books[t].state = state2;
    }
    else
    {
        printf("书籍不存在\n");
    }

} // 更新图书
void borrowBook()
{ // 借阅图书
    if (now_user.bid == 0)
    {
        printf("您没有借阅图书\n");
        int bid; // 借阅图书编号
        printf("请输入借阅图书编号：\n");
        scanf("%d", &bid);
        // 查找图书
        int i;
        for (i = 0; i < bookln; i++)
        {
            if (books[i].bid == bid)
            { // 找到该书
                if (books[i].state == 0)
                {                       
                    books[i].state = 1; 
                    now_user.bid = bid; // 更新用户借阅图书编号
                    printf("借阅成功\n");
                    return;
                }
                else
                {
                    printf("该书已经被借阅\n");
                    return;
                }
            }
        }
        printf("没有找到该书\n");
        return;
    }
}
#if 1
void returnBook()
{
    int i;
    int bid;
    if (now_user.bid == 0)
    {
        printf("您未借任何书籍\n");
        return;
    }
    else
    {
        // printf("请输入您要归还的图书编号:");
        // scanf("%d", &bid);
        // now_user.bid = bid;
        for (i = 0; i < bookln; i++)
        {
            if (books[i].bid == now_user.bid)
            {
                books[i].state = 0;
                now_user.bid = 0;
                printf("归还成功!\n");
                return;
            }
        }
    }

} // 归还图书
#endif