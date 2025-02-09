#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct TreeNode{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
}treeNode_t;//二叉树
treeNode_t * createTree(){//动态创建二叉树
    int data;
    printf("请输入节点值:");
    scanf("%d",&data);
    if(data==-1){
        return NULL;//如果赋值-1，表示节点为NULL
    }
    treeNode_t *newNode=(treeNode_t*)malloc(sizeof(treeNode_t));
    assert(newNode);
    newNode->data=data;//赋值
    //递归创建左子树
    newNode->left=createTree();
    //递归创建右子树
    newNode->right=createTree();
    return newNode;
}
void preOrderTraversal(treeNode_t *node){//前序遍历二叉树
    if(node==NULL){
        return;
    }
    printf("%d",node->data);//打印根节点
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}
void printTree(treeNode_t* root, int level) {//立体打印
    if (root == NULL) return;
    // 先递归打印右子树，层级加 1
    printTree(root->right, level + 1);
    // 根据层级进行缩进
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    // 打印当前节点的值
    printf("%d\n", root->data);
    // 递归打印左子树，层级加 1
    printTree(root->left, level + 1);
}
void freeTree(treeNode_t *root){
    if (root == NULL) {
        return;
    }
    freeTree(root->left);// 递归释放左子树
    freeTree(root->right);// 递归释放右子树
    free(root);// 释放当前节点
}
int main(int argc,char*argv[]){
    treeNode_t *root=createTree();
    // preOrderTraversal(root);//前序遍历
    printTree(root,0);
    freeTree(root);
    return 0;
}