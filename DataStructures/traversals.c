#include "myHeader.h"
#include<stdio.h>

struct stackNode* stack = NULL;
struct stackNode* top = NULL;
struct stackNode* temp2 = NULL;
struct node* queue[10];

void inOrderTraversal(struct node *head)
{
	temp = head;

	while (1)
	{
		if (temp != NULL)
		{
			top = push(temp);
			temp = temp->left;
		}
		else
		{
			if (top != NULL) //If stack is not empty then we pop out the elements
			{
				temp = pop();
				printf("%d, ", temp->data);

				temp = temp->right;
			}
			else
			{
				//When stack is empty, we come out of this loop
				break;
			}
		}
	}
}

void preOrderTraversal(struct node* head)
{
	temp = head;

	while (1)
	{
		while (temp != NULL)
		{
			printf("%d, ", temp->data);

			if (temp->right)
			{
				top = push(temp->right);
			}
			temp = temp->left;
		}

		if (top != NULL)
		{
			temp = pop();
		}
		else
		{
			break;
		}
	}
}

void postOrderTraversal(struct node* head)
{
	temp = head;

	do
	{
		while (temp != NULL)
		{
			if (temp->right)
			{
				top = push(temp->right);
			}
			top = push(temp);

			//Move to the left child
			temp = temp->left;
		}

		temp = pop();

		if(top != NULL && temp->right && top->treePointer == temp->right)
		{
			pop();
			push(temp);
			temp = temp->right;
		}
		else
		{
			printf("%d, ", temp->data);
			temp = NULL;
		}
	} while (top != NULL);
}

struct stackNode* push(struct node* ptr)
{
	stack = (struct stackNode*)malloc(sizeof(struct stackNode));
	stack->treePointer = ptr;
	stack->next = NULL;
	if (top == NULL)
	{
		top = stack;
	}
	else
	{
		temp2 = top;
		top = stack;
		stack->next = temp2;
	}

	return top;
}

struct node* pop()
{
	if (top == NULL)
	{
		printf("underflow\n");
		return 0;
	}
	else
	{
		temp2 = top;
		top = top->next;
		return(temp2->treePointer);
	}
}

void bfsTraversal(struct node* head)
{
	int rear = -1;
	int front = -1;

	temp = head;

	while(temp != NULL)
	{
		printf("%d, ", temp->data);

		// Enqueue Left child
		if(temp->left)
		{
			rear = rear + 1;
			queue[rear] = temp->left;
		}

		//Enqueue Right Child
		if(temp->right)
		{
			rear = rear + 1;
			queue[rear] = temp->right;
		}

		//Dequeue and make the dequeued node as temp to print
		front = front + 1;
		temp = queue[front];
	}
	printf("\n");
}