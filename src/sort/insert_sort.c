#include <stdio.h>
#include <string.h>
#include "sort.h"

//插入排序
//插入排序可以利用以前的有序性减少交换和遍历次数
//稳定的排序
//平均时间复杂度O(n2)
//最好情况O(n)
//最坏情况O(n2)
//空间复杂度O(1)


void insert_sort2(int array[],int len)
{
	for(int i = 1; i < len; i++)
	{
		for(int j = i; j > 0; j--)
		{
			if(array[j-1] > array[j])
			{
				swap(array,j-1,j);
			}
			else
			{
				break;
			}
		}
	}
	
	return ;
}

//插入排序优化后
void insert_sort(int array[],int len)
{
	int tmp;
	int i,j;
	
	for(i = 1; i < len; i++)
	{
		tmp = array[i];
		for(j = i; j > 0; j--)
		{
			if(array[j-1] > tmp)
			{
				array[j] = array[j-1];
			}
			else
			{
				break;
			}
		}

		if(i != j)
		{
			array[j] = tmp;
		}
	}
	
	return ;
}


