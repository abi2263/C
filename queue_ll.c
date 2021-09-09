#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
} *front = NULL, *rear = NULL;

void insert(int);
void delet();
void display();

void main()
{
	int choice, value;
	printf("\n\t  MENU\n\n");
	printf("\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Exit");
	do
	{
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the value to be insert: ");
			scanf("%d", &value);
			insert(value);
			break;
		case 2:
			delet();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("EXIT!");
			break;
		default:
			printf("\nPlease enter the valid choice (1/2/3/4)");
		}
	}while(choice!=4);
}

void insert(int value)
{
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if (front == NULL)
		front = rear = newNode;
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	printf("Successfully enqueued!");
}

void delet()
{
	if (front == NULL)
		printf("\nQueue is Empty!");
	else
	{
		struct Node *temp = front;
		front = front->next;
		printf("Deleted element is %d", temp->data);
		free(temp);
		printf("\nSuccessfully dequeued!");
	}
}

void display()
{
	if (front == NULL)
		printf("\nQueue is Empty!");
	else
	{
		struct Node *temp = front;
		printf("List elements are: ");
		while (temp->next != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d ", temp->data);
	}
}