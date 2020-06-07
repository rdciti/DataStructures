#include<stdio.h>
#include  "myHeader.h"

struct node* inorderSuccessor(struct node* head, int findMySuccessor)
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
    
    if(current == NULL) return current;

    /* Case 1: When Current Node has Right SubTree */
    if(current->right != NULL)
    {
        struct node* temp = current->right;
        while(temp->left != NULL)
        {
            temp = temp->left;
        }

        printf("\nThe successor is: %d\n", temp->data);
        return temp;
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
        return successor;
    }

}

int deleteNode(struct node* head, int deleteMe)
{
    struct node* temp   = head;
    struct node* temp3  = head;
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

    // 3 cases of delete
    //if node is a leaf
    if (temp->right == NULL && temp->left == NULL)
    {
        if (temp->data > parent->data)
        {
            parent->right = NULL;
        }
        else
        {
            parent->left = NULL;
        }

        //Freeing the memory
        free(temp);
    }

    //if node has onlyone child
    else if (temp->right == NULL || temp->left == NULL)
    {
        if (temp->left != NULL) 
        {
            parent->left = temp->left;
        }
        else 
        {
            parent->right = temp->right;
        }
        free(temp);
    }

    //if node has two children
    else if (temp->right != NULL && temp->left != NULL)
    {
        struct node* success = inorderSuccessor(head, deleteMe);

        parent = NULL;
        while (temp3 != NULL)
        {
            if (success->data > temp3->data)
            {
                parent = temp3;
                temp3 = temp3->right;
            }
            else if(success->data < temp3->data)
            {
                parent = temp3;
                temp3 = temp3->left;
            }
            else
            {
                break;
            }
        }

        if (success == parent->left)
        {
            parent->left = success->left;
        }
        else if (success == parent->right)
        {
            parent->right = success->right;
        }


        
        
        temp->data = success->data;

        //Free the successor (and temp3) as its data has already been copied to temp
        free(success);
    }

    return 0;
}