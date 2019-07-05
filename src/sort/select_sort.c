#include <stdio.h>
#include <string.h>
#include "sort.h"

//选择排序
//该种排序相比冒泡排序，需要较少次数的数据交换，因此测试性能比冒泡排序要好

//不稳定的排序
//平均时间复杂度O(n2)
//最好情况O(n2)
//最坏情况O(n2)
//空间复杂度O(1)


void select_sort(int array[],int len)
{
	int min_index;
	
	for(int i = 0; i < len-1; i++)
	{
		min_index = i;
		for(int j = i+1; j < len; j++)
		{
			if(array[min_index] > array[j])
			{
				min_index = j;
			}
		}

		if(min_index != i)
		{
			swap(array,min_index,i);
		}
	}
	
	return ;
}


