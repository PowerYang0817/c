#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#ifndef FUNLIB_H
#define FUNLIB_H
typedef struct ListNode {
    int bid;
    char bname[50];
    char author[30]; // 作者
    float price;
    char publish[100]; // 出版社
    int state;         // 1  0未借出
    struct ListNode *next;
}bookList;
typedef struct ListUser
{
    char uname[20];
    char password[30];
    int bid; //  -1  0未 或Book编号
    struct ListUser *next;
} userList; 
static userList *nowUser=NULL;//当前用户

userList * createUser();//初始化用户
bookList * createBook();//初始化图书
int login(userList *head,bookList *bookhead);//登录
void showMenu(userList *userhead,bookList *bookhead);//菜单
void rootMenu(userList *userhead,bookList *bookhead);//管理员菜单
void userMenu(userList *userhead,bookList *bookhead);//用户菜单

void showBook(bookList *head);//打印图书信息

void addBook(bookList *head);//添加图书
void deleteBook(bookList *head);//删除图书
void updateBook(bookList *head);//修改图书信息

void borrowBook(bookList *head);//借书
void returnBook(bookList *head);//还书

void freeList(userList *head);//释放链表
void freeBook(bookList *head);//释放链表
#endif