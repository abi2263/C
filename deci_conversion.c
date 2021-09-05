#include<stdio.h> 

void convert (int num, int b) 
{ 
int rem;
rem = num%b; 
if(num==0) 
	return ; 
convert(num/b, b); 
if(rem < 10) 
	printf("%d", rem); 
else 
	printf("%c", rem-10+'a'); 
}

int main() 
{ 
	int num; 
	printf("Enter a positive decimal number : ");
	scanf("%d", &num); 
	printf("\nBinary number : "); 
	convert(num, 2);
	
	printf("\nOctal number : "); 
	convert(num, 8);
	
	printf("\nHexadecimal number : "); 
	convert(num, 16); 
	
	printf("\n");
	
	return 0; 
}