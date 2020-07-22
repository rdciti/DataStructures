#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
	int height;
};

struct node* head = NULL;
struct node* temp = NULL;
struct node* prev = NULL;
struct node* queue[10];

int NodeHeight(struct node* p)
{
	int hl, hr;

	if (p != NULL)
	{
		if (p->left)
		{
			hl = p->left->height;
		}
		else
		{
			hl = 0;
		}

		if (p->right)
		{
			hr = p->right->height;
		}
		else
		{
			hr = 0;
		}
	}

	printf("\nHeight of left subtree: %d\n", hl);
	printf("\nHeight of right subtree: %d\n", hr);

	return hl > hr ? hl + 1 : hr + 1;
}

void createtree(int num)
{
	if (head == NULL)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->data = num;
		head->height = 1;
		head->left = head->right = NULL;
	}
	else
	{
		temp = head;
		prev = head;

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
		temp->height = 1;
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

void bfsTraversal(struct node* head)
{
	int rear = -1;
	int front = -1;

	temp = head;

	while (temp != NULL)
	{
		printf("%d, ", temp->data);

		// Enqueue Left child
		if (temp->left)
		{
			rear = rear + 1;
			queue[rear] = temp->left;
		}

		//Enqueue Right Child
		if (temp->right)
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

int main()
{
	printf("Inserting 10\n");
	createtree(10);
	printf("Inserting 5\n");
	createtree(5);
	printf("Inserting 3\n");
	createtree(3);
	printf("Inserting 2\n");
	createtree(2);
	printf("Inserting 1\n");
	createtree(1);

	bfsTraversal(head);

	return 0;
}