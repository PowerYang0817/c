#include "funlib.h"

int main(int argc, char const *argv[]){
    //初始化用户
    userList *headUser = createUser();
    //初始化图书
    bookList *headBook = createBook();
    showMenu(headUser,headBook);
    return 0;
}
