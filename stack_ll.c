#include <stdio.h>
#include <stdlib.h>

void push(int);
void pop();
void display();

struct node
{
	int data;
	struct node *next;
};
struct node *top = NULL, *temp;
void main()
{
	int choice, data;
	printf("\t MENU\n");
	printf("\n\t1.Push \n\t2.Pop \n\t3.Display \n\t4.Exit");
	do
	{
		printf("\n\nEnter ur choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter a element :");
			scanf("%d", &data);
			push(data);
			printf("Successfully pushed!");
			break;
		case 2:
			pop();
			printf("Successfully popped!");
			break;
		case 3:
			display();
			break;
		case 4:
			printf("EXIT!");
			break;
		default:
			printf("Please enter the valid choice (1/2/3/4)");
		}
	} while (choice != 4);
}

void push(int data)
{
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = top;
	top = temp;
}

void pop()
{
	if (top != NULL)
	{
		printf("The popped element is %d\n", top->data);
		top = top->next;
	}
	else
		printf("\nStack is underflow!");
}

void display()
{
	temp = top;
	if (temp == NULL)
		printf("\nStack is empty!\n");
	printf("\nList elements are: ");
	while (temp != NULL)
	{
		printf(" %d ", temp->data);
		temp = temp->next;
	}
}