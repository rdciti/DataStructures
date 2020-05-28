#include<stdio.h>
#include  "myHeader.h"

int inorderSuccessor(struct node* head, int findMySuccessor)
{
    //Find my address
    struct node* current = NULL;

    current = head;

    while(current != NULL)
    {
        if (findMySuccessor > current->data)
		{
			current = current->right;
		}
		else if (findMySuccessor < current->data)
		{
			current = current->left;
		}
        else
        {
            break;
        }
    }
    
    if(current == NULL) return 1;

    /* Case 1: When Current Node has Right SubTree */
    if(current->right != NULL)
    {
        struct node* temp = current->right;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }

        printf("\nThe successor is: %d\n", temp->data);
    }

    /*Case 2: When there is no Right SubTree */
    else
    {
        struct node* successor = NULL;
        struct node* parent    = head;

        while(parent != current)
        {
            if(current->data < parent->data)
            {
                successor = parent;
                parent    = parent->left;
            }
            else
            {
                parent = parent->right;
            }
            
        }

        printf("\nThe successor is: %d\n", successor->data);
    }

    return 0;
}

int deleteNode(struct node* head, int deleteMe)
{
    struct node* temp   = head;
    struct node* parent = NULL;

    while(temp!=NULL)
    {
        if(deleteMe > temp->data)
        {
            parent = temp;
            temp   = temp->right;
        }
        else if(deleteMe < temp->data)
        {
            parent = temp;
            temp   = temp->left;
        }
        else
        {
            break;
        }
        
        
    }
    printf("\nDeleteMe: %d", deleteMe);
    printf("\nParent: %d", parent->data);
    printf("\nTemp: %d", temp->data);

    return 0;
}