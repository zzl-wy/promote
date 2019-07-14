#include <stdio.h>
#include <string.h>
#include "sort.h"

//归并排序

//不稳定的排序,需要额外的空间
//平均时间复杂度O(nlogn)
//最好情况O(nlogn)
//最坏情况O(nlogn)
//空间复杂度O(n)

//将array[l...mid]和array[mid+1...r]两部分进行归并
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

//自顶向下的归并排序
//递归使用归并排序，对array[left...right]的范围进行排序
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

void __merge_sort2(int array[],int l,int r)
{
	int mid;
	
	if(l >= r)return;

	mid = (l + r)/2;
	__merge_sort(array, l, mid);
	__merge_sort(array, mid+1, r);

	if(array[mid] > array[mid+1])//数据完全有序的时候的优化
		__merge(array,l,mid,r);
	return;
}


void __merge_sort3(int array[],int l,int r)
{
	int mid;

#if 0
	if(l >= r)return;
#else
	if(r-l <= 7)
	{
		insert_sort(array+l,r-l+1);//在小规模数据的时候使用插入排序
		return;
	}
#endif

	mid = (l + r)/2;
	__merge_sort(array, l, mid);
	__merge_sort(array, mid+1, r);

	if(array[mid] > array[mid+1])
		__merge(array,l,mid,r);
	return;
}


void merge_sort(int array[],int len)
{
	__merge_sort3(array, 0, len);
	return ;
}
#define MIN(x,y) (x)>(y)?(y):(x)

//自下向上的归并排序，使用迭代代替递归。可以用于链表
void merge_sortBU(int array[],int len)
{
	for(int sz = 1; sz <= len; sz*=2)
	{		
		for(int i = 0; i+sz < len; i=i+sz*2)
		{
			__merge(array,i,i+sz-1,MIN(i+sz*2-1,len-1));
		}
	}

	return;
}

//使用归并排序的思路求解逆序对的个数



