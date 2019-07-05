#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "sort.h"

void print_array(int array[],int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%d,",array[i]);

		if(i%16==0&&i>0)
		{
			printf("\n");
		}
	}	
	printf("\n");
}

void swap(int array[],int src,int dst)
{
	int tmp;
	
	tmp = array[src];
	array[src] = array[dst];
	array[dst] = tmp;
}
int* generate_random_array(int n, int range_l, int range_r) 
{
	int* array;
	
	array = malloc(sizeof(int)*n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		array[i] = rand() % (range_r - range_l + 1) + range_l;
	return array;
}

int *generate_nearly_orderedarray(int n, int swapTimes)
{
	int* array;
	
	array = malloc(sizeof(int)*n);
	for(int i = 0 ; i < n ; i ++ )
		array[i] = i;

	srand(time(NULL));
	for( int i = 0 ; i < swapTimes ; i ++ )
	{
		int posx = rand()%n;
		int posy = rand()%n;
		swap(array,posx,posy);
	}

	return array;
}

int *copy_intarray(int a[], int n)
{
	int* newarray;
	
	newarray = malloc(sizeof(int)*n);
	for(int i = 0 ; i < n ; i ++ )
	{
		newarray[i] = a[i];
	}	
	
	return newarray;
}

int issorted(int arr[], int n) 
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return 0;		
	}

	return 1;
}

void test_sort_func(const char* sort_name, void (*sort)(int*, int), int arr[], int n) 
{
	double t;
	clock_t startTime = clock();
	sort(arr,n);
	clock_t endTime = clock();
	
	t = (double)(endTime - startTime)/CLOCKS_PER_SEC;
	printf("%s:%f s\n",sort_name,t);

	assert(issorted(arr, n));
	return;
}

void test_sort_func2(int n,void (*sort)(int*, int))
{
    int* arr1 = generate_random_array(10,0,100);

	print_array(arr1,10);
	bubble_sort(arr1,10);
	print_array(arr1,10);

	free(arr1);
	return ;
}

