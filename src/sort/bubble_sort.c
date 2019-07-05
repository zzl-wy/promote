#include <stdio.h>
#include <string.h>
#include "sort.h"

//冒泡排序
//稳定的排序
//平均时间复杂度O(n2)
//最好情况O(1)在完全有序的情况下
//最坏情况O(n2)
//空间复杂度O(1)

//从高往低处排
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

//从低往高处排
void bubble_sort2(int array[],int len)
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

//带有优化的冒泡排序
void bubble_sort(int array[],int len)
{
	int max = len-1;
	int flag = 0;
	
	for(int i = 0; i < max; i++)
	{
		flag = 1;
		for(int j = max; j > i; j--)
		{
			if(array[j-1] > array[j])
			{
				swap(array, j-1,j);
				flag = 0;
			}
		}

		if(flag)
		{
			break;
		}
	}
	
	return ;
}


