#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rchild;
}tree_t;
tree_t * create()
{
	char ch;
	scanf("%c",&ch);
	if(ch=='#')
	{
		return NULL;
	}
	tree_t *r=(tree_t*)malloc(1*sizeof(tree_t));
	if(r==NULL)
	{
		printf("r malloc failed\n");
		return NULL;
	}
	r->data=ch;
	r->lchild=create();
	r->rchild=create();
	return r;
}
void pre(tree_t *r)
{
	if(r==NULL)
	return;	
	printf("%c ",r->data);
	pre(r->lchild);
	pre(r->rchild);
}
void in(tree_t *r)
{
	if(r==NULL)	
	return;
	r->lchild=create();
	printf("%c ",r->data);
	r->rchild=create();
}
void hou(tree_t *r)
{
	if(r==NULL)
	return;
	r->lchild=create();
	r->rchild=create();
	printf("%c ",r->data);
}
void clear(tree_t *r)
{
	if(r==NULL)
	return;
	clear(r->lchild);
	clear(r->rchild);
	free(r);
}
int main(int argc, const char *argv[])
{
	tree_t *r=create();
	printf("前序:\n");
	pre(r);
	printf("\n");
	printf("中序:\n");
	in(r);
	printf("\n");
	printf("后序:\n");
	hou(r);
	printf("\n");
	clear(r);
	return 0;
}