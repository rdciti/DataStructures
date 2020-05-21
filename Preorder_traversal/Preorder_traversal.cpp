#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left, * right;
};

struct node* head = NULL;
struct node* temp = NULL;
struct node* prev = NULL;




struct stackNode
{
	struct node* treePointer;
	struct stackNode* next;
};

struct stackNode* stack = NULL;
struct stackNode* top = NULL;
struct stackNode* temp2 = NULL;


void createtree(int);
int search(int);

void traverse();
void push(struct node*);
struct node* pop();


int main()
{
	int choice = 0, num, flag = 0, key;

	do
	{
		printf("enter your choice: \n1. insert\n2. search\n3. traverse\n4. exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("enter the element to insert: ");
			scanf("%d", &num);
			createtree(num);
			break;

		case 2:
			printf("enter the node to search:");
			scanf("%d", &key);
			flag = search(key);

			if (flag)
			{
				printf("\nFOUND in the tree\n");
			}
			else
			{
				printf("\nNOT found\n");
			}
			break;

		case 3:
			printf("\n\nPREORDER traversal: ");
			traverse();

		case 4:
			printf("\n\nFreeing the memory\n\n");
			head = NULL;
			free(head);
			break;
		}
	} while (choice != 4);

	return 0;
}

void createtree(int num)
{
	temp = head;
	prev = head;

	if (head == NULL)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->data = num;
		head->left = head->right = NULL;
	}
	else
	{
		while (temp != NULL)
		{
			if (num > temp->data)
			{
				prev = temp;
				temp = temp->right;
			}
			else
			{
				prev = temp;
				temp = temp->left;
			}
		}

		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->right = NULL;
		temp->left = NULL;

		if (num >= prev->data)
		{
			prev->right = temp;
		}
		else
		{
			prev->left = temp;
		}
	}
}

int search(int key)
{
	temp = head;
	while (temp != NULL)
	{
		if (key > temp->data)
		{
			temp = temp->right;
		}
		else if (key < temp->data)
		{
			temp = temp->left;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

void traverse()
{
	temp = head;


	while(1)
	{
		while (temp != NULL)
		{
			printf("%d, ", temp->data);

			if (temp->right)
			{
				push(temp->right);
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

void push(struct node* ptr)
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
}

struct node* pop()
{
	if (top == NULL)
	{
		printf("underflow\n");
	}
	else
	{
		temp2 = top;
		top = top->next;
		return(temp2->treePointer);
	}
}