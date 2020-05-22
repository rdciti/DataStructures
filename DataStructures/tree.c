#include<stdio.h>

#include "myHeader.h"

struct node* head = NULL;
struct node* temp = NULL;
struct node* prev = NULL;

int main()
{
	int choice = 0, num, flag = 0, key;
	//inOrderTraversal();
	do
	{
		printf("enter your choice: \n1. insert\n2. search\n3. traverse\n4. exit\n");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			//inorderTraversal();
			printf("enter the element to insert: ");
			scanf_s("%d", &num);
			createtree(num);
			break;

		case 2:
			printf("enter the node to search:");
			scanf_s("%d", &key);
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
			printf("\n\nTraversals: ");
			traverse(head);

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

void traverse(struct node* head)
{
	printf("\n\n");

	printf("Inorder   Traversal -> ");
	inOrderTraversal(head);

	printf("\nPreorder  Traversal -> ");
	preOrderTraversal(head);

	printf("\nPostorder Traversal -> ");
	postOrderTraversal(head);
}