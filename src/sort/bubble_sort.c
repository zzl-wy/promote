#include <stdio.h>
#include <string.h>
#include "sort.h"

void bubble_sort1(int array[],int len)
{
	int max = len-1;
	
	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < max-i; j++)
		{
			if(array[j] > array[j+1])
			{
				swap(array, j,j+1);
			}
		}
	}

	return ;
}

void bubble_sort(int array[],int len)
{
	int max = len-1;
	
	for(int i = 0; i < max; i++)
	{
		for(int j = max; j > i; j--)
		{
			if(array[j-1] > array[j])
			{
				swap(array, j-1,j);
			}
		}
	}
	
	return ;
}


