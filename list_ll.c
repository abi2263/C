#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *p, *temp, *head, *ptr;
void create(void);
void insert(void);
void delete (void);
void display(void);
int j, pos, count;

void main()
{
    int n, i = 1, choice;
    p = NULL;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    count = n;

    while (i <= n)
    {
        create();
        i++;
    }

    printf("\n\t  MENU");
    printf("\n\t1.Insert \n\t2.Delete \n\t3.Display \n\t4.Exit\n");
    do
    {
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            count++;
            break;
        case 2:
            delete();
            count--;
            if (count == 0)
            {
                printf("\nList is empty!\n");
            }
            break;
        case 3:
            printf("List elements are:\n");
            display();
            printf("\n");
            break;
        case 4:
            printf("EXIT!\n");
            break;
        default:
            printf("Please Enter the valid choice (1/2/3/4)! \n");
            break;
        }
    } while (choice != 4);
}

void create()
{
    if (p == NULL)
    {
        p = (node *)malloc(sizeof(node));
        printf("Enter the element: ");
        scanf("%d", &p->data);
        p->next = NULL;
        head = p;
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter the element: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        p->next = temp;
        p = temp;
    }
}

void insert()
{
    temp = head;
    p = (node *)malloc(sizeof(node));
    printf("Enter the element to be inserted: ");
    scanf("%d", &p->data);
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head = p;
        head->next = temp;
    }
    else
    {
        for (j = 1; j < (pos - 1); j++)
            temp = temp->next;
        p->next = temp->next;
        temp->next = p;
        temp = p;
    }
    printf("\nSuccessfully inserted!\n");
}

void delete ()
{
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        head = head->next;
    }
    else
    {
        temp = head;
        for (j = 1; j < (pos - 1); j++)
            temp = temp->next;
        ptr = temp->next->next;
        temp->next = ptr;
    }
    printf("\nSuccessfully deleted!\n");
}

void display()
{
    temp = head;
    while (temp->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}