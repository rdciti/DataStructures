#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* temp, * head, * prev = NULL;

void createTree(int);
int search(int);
void push(struct node*);
struct node* pop();
void intraverse(struct node*);
void pretraverse(struct node*);

void createTree(int num)
{
    temp = head;
    prev = temp;

    if (head == NULL)
    {
        head = (struct node*)malloc(sizeof(struct node));
        head->data = num;
        head->right = NULL;
        head->left = NULL;
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
            else if (num < temp->data)
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

struct stackNode
{
    struct node* treePointer;
    struct stackNode* next;
};

struct stackNode* temp2, * stack, * top = NULL;

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
        printf("\nunderflow\n");
        return 0;
    }
    else
    {
        temp2 = top;
        top = top->next;
        return(temp2->treePointer);
    }
}

void intraverse(struct node* head)
{
    temp = head;
    while (1)
    {
        if (temp != NULL)
        {
            push(temp);
            temp = temp->left;
        }
        else
        {
            if (top != NULL)
            {
                temp = pop();
                printf("%d,", temp->data);
                temp = temp->right;
            }
            else
            {
                break;
            }
        }
    }
}

//preorder
void pretraverse(struct node* head)
{
    temp = head;
    while (1)
    {
        while (temp != NULL)
        {
            printf("%d,", temp->data);

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



int main(void)
{
    createTree(4);
    createTree(6);
    createTree(11);
    createTree(16);



    int flag;
    flag = search(11);
    if (flag)
    {
        printf("\nFound\n");
    }
    else
    {
        printf("\nnot found\n");
    }

    printf("\n");
    intraverse(head);
    printf("\n");
    pretraverse(head);

    free(head);
    return 0;
}