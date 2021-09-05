#include <stdio.h>

void sort(int n, int *ptr)
{
	int i, j, t;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (*(ptr + j) < *(ptr + i))
			{
				t = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = t;
			}
		}
	}

	printf("Sorted array:");

	for (i = 0; i < n; i++)
		printf("%d ", *(ptr + i));
}

int main()
{
	int arr[] = {0, 23, 14, 45, 32, 6};
	sort(sizeof arr / sizeof arr[0], arr);

	return 0;
}