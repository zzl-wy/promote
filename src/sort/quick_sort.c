#include <stdio.h>
#include <string.h>
#include "sort.h"

static int partition(int array[],int low,int high)
{
	int piovt;

	piovt = array[low];
	while(low < high)
	{
		while(low < high && array[high] >= piovt)
		{
			high--;
		}
		array[low] = array[high];

		while(low < high && array[low] <= piovt)
		{
			low++;
		}
		array[high] = array[low];
		
	}
	array[low] = piovt;
	return low;
}
static void _quick_sort(int array[],int low,int high)
{
	int piovt;
	if(low < high)
	{
		piovt = partition(array,low,high);
		_quick_sort(array,low,piovt-1);
		_quick_sort(array,piovt+1,high);
	}
}

void quick_sort2(int array[],int len)
{
	_quick_sort(array,0,len-1);
}

int partition1(int array[],int left,int right)
{
	int pivot;

	pivot = array[left];
	while(left<right)
	{
		while(left<right&&array[right]>=pivot)
		{
			right--;
		}
		array[left] = array[right];

		while(left<right&&array[left]<=pivot)
		{
			left++;
		}
		array[right] = array[left];
	}
	
	array[left] = pivot;
	return left;
}

void _quick_sort1(int array[],int left,int right)
{
	int pivot;
	
	if(left >= right)
	{
		return ;	
	}

	pivot = partition1(array,left,right);
	_quick_sort1(array, left, pivot-1);
	_quick_sort1(array, pivot+1, right);
	
	return ;
}

void quick_sort(int array[],int len)
{
	_quick_sort1(array, 0, len-1);
}

