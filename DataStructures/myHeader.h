#ifndef INORDERFUNCTION_H_INCLUDED
#define INORDERFUNCTION_H_INCLUDED

#include<stdlib.h>

struct node
{
	int data;
	struct node* left, * right;
};

struct stackNode
{
	struct node* treePointer;
	struct stackNode* next;
};


extern struct node* head;
extern struct node* temp;
extern struct node* prev;

extern struct stackNode* stack;
extern struct stackNode* top;
extern struct stackNode* temp2;

struct stackNode* push(struct node*);
struct node* pop();

void createtree(int);
int search(int);
void traverse(struct node*);

void inOrderTraversal(struct node*);
void preOrderTraversal(struct node*);
void postOrderTraversal(struct node*);

#endif // !INORDERFUNCTION_H_INCLUDED