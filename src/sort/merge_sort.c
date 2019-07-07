#include <stdio.h>
#include <string.h>
#include "sort.h"

//归并排序

//不稳定的排序
//平均时间复杂度O(nlogn)
//最好情况O(nlogn)
//最坏情况O(nlogn)
//空间复杂度O(n)

static void __merge(int array[],int left,int mid,int right)
{
	int temp[right-left+1];
	int i = 0;
	int left_pos;
	int right_pos;

	//先将数据复制到临时缓冲区，备用
	for(i = 0; i < right-left+1; i++)
	{
		temp[i] = array[left+i];
	}
	
	left_pos = left;
	right_pos = mid+1;//注意此处应该和调用__merge_sort给出的边界一致
	for(i = left; i <= right; i++)
	{
		if(left_pos > mid)
		{
			array[i] = temp[right_pos-left];
			right_pos++;
		}
		else if(right_pos > right)
		{
			array[i] = temp[left_pos-left];
			left_pos++;
		}
		else
		{
			if(temp[left_pos-left] > temp[right_pos-left])
			{			
				array[i] = temp[right_pos-left];
				right_pos++;
			}
			else
			{
				array[i] = temp[left_pos-left];
				left_pos++;
			}
		}
	}

	return ;
}

void __merge_sort(int array[],int left,int right)
{
	int mid;
	
	if(left >= right)
	{
		return ;
	}

	mid = (left + right)/2;
	__merge_sort(array,left, mid);
	__merge_sort(array,mid+1,right);
	__merge(array,left,mid,right);

	return ;
}

void merge_sort2(int array[],int len)
{
	__merge_sort(array, 0, len);
	return ;
}

#define min(x,y) (x)>(y)?(y):(x)
void merge_sort(int array[],int len)
{
	for(int sz = 1; sz <= len;sz*=2)
	{
		for(int i = 0;i+sz < len; i+=sz*2)
		{
			__merge(array,i,i+sz-1,min(i+2*sz-1,len-1));
		}
	}

	return ;
}



