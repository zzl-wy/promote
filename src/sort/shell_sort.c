#include <stdio.h>
#include <string.h>
#include "sort.h"

//希尔排序

//不稳定的排序
//平均时间复杂度O(nlogn)
//最好情况O(nlog2n)
//最坏情况O(nlog2n)
//空间复杂度O(1)

//希尔排序是基于插入排序的以下两点性质而提出改进方法的：
//插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率；
//但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位；
//希尔排序（shell sort）这个排序方法又称为缩小增量排序，是1959年D·L·Shell提出来的。该方法的基本思想是：设待排序元素序列有n个元素，首先取一个整数increment（小于n）作为间隔将全部元素分为increment个子序列，所有距离为increment的元素放在同一个子序列中，在每一个子序列中分别实行直接插入排序。然后缩小间隔increment，重复上述子序列划分和排序工作。直到最后取increment=1，将所有元素放在同一个子序列中排序为止。

void shell_sort2(int array[],int len)
{
	int gap = 1;	
	int tmp;
	int j;

	while (gap < len) 
	{
		gap = gap * 3 + 1;//计算gap值，该值是*3+1大于长度的第一个数字
	}

	while(gap > 0)
	{
		for(int i = gap; i < len; i++)
		{
			tmp = array[i];
			//for(j = i; j > 0; j-= gap)//此处判断条件应该为gap,开始以为是0，如果是0的话边界判断会有问题
			for(j = i; j >= gap; j-= gap)
			{
				if(array[j-gap] > tmp)
				{
					array[j] = array[j-gap];
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
		
		gap /= 3;
	}
	
	return ;
}

void shell_sort33(int array[],int len)
{
	int gap = 1;

	while(gap < len)
	{
		gap = 3*gap+1;
	}

	while(gap > 0)
	{
		for(int i = gap; i < len; i++)
		{
			int j;
			int tmp;

			tmp = array[i];
			for(j = i; j >= gap; j -= gap)//错误
			{
				if(tmp >= array[j-gap])//错误
				{
					break;
				}

				array[j] = array[j-gap];
			}

			if(i != j)
			{
				array[j] = tmp;
			}
		}
		
		gap /= 3;
	}

	return ;
}

void shell_sort(int array[],int len)
{
	int gap = 1;

	while(gap < len)
	{
		gap = gap * 3 + 1;
	}

	while(gap > 0)
	{
		for(int i = gap; i < len; i++)
		{
			int j;
			int tmp =  array[i];
			
			for(j = i; j >= gap; j-= gap)
			{
				if(array[j-gap] <= tmp)
				{
					break;
				}
				array[j] = array[j-gap];
			}

			if(i != j)
			{
				array[j] = tmp;
			}
		}
		
		gap = gap / 3;
	}
}
