#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct emp
{
    int empno[10];
    char name[20];
    int bp, allow, ded, npay;

} emp[20];


void main()
{
    int i = 0, n = 0;
    char answer;
    int more_data = 1;
    printf("Enter how many employees :");
    scanf("%d", &more_data);
    while (i < more_data)
    {
        printf("\nEnter Employee %d number : ",i+1);
        scanf("%d", &emp[i].empno);
        printf("\nEnter Employee %d name : ",i+1);
        scanf("%s", &emp[i].name);
        printf("\nEnter the basic pay, allowances & deductions : ");
        scanf("%d %d %d", &emp[i].bp, &emp[i].allow, &emp[i].ded);
        emp[i].npay = emp[i].bp + emp[i].allow - emp[i].ded;
        i++;
    }

     i = 0;
     printf("\nEmp.no.  Name \t Bpay \t Allow \t Ded \t Npay \n\n") ;

     while (i < more_data)
     {
        printf("%d \t %s \t %d \t %d \t %d \t %d \n", emp[i].empno, emp[i].name, emp[i].bp, emp[i].allow, emp[i].ded, emp[i].npay);
        i++;
    }
}