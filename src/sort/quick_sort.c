#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#if 0
int __parition_q(int array[],int l,int r)
{
	int pivot;

	swap(array, l,rand()%(r-l+1)+l);
	pivot = array[l];
	while(l < r)
	{
		while(l < r && array[r] > pivot)
		{
			r--;
		}
		array[l] = array[r];

		while(l < r && array[l] < pivot)
		{
			l++;
		}
		array[r] = array[l];
	}

	array[l] = pivot;
	return l;
}
#endif


int __parition2(int array[],int l,int r)
{
	int pivot;

	swap(array, l,rand()%(r-l+1)+l);
	pivot = array[l];

	//array[l+1,i]<=v;array(j...r]>=v
	int i = l+1;
	int j = r;

	while(1)
	{
		while(i <= r && array[i] < pivot)
		{
			i++;
		}

		while(j >= l+1 && array[j] > pivot)
		{
			j--;
		}

		if(i > j)
		{
			break;
		}

		swap(array, i,j);
		i++;
		j--;
	}

	swap(array, l,j);
	return j;
}

void __quick_sort2(int array[],int l,int r)
{
	int pivot;

#if 0
	if(l >= r)
	{
		return ;
	}
#else
	if(r-l <= 7)
	{
		insert_sort(array+l,r-l+1);//在小规模数据的时候使用插入排序
		return;
	}
#endif
	
	pivot = __parition2(array,l,r);
	__quick_sort2(array,l,pivot-1);
	__quick_sort2(array,pivot+1,r);
	
	return;
}

void quick_sort2(int array[],int len)
{
	srand(time(NULL));
	__quick_sort2(array,0,len-1);
}

//=====================================================================
//三路快速排序

void __quick_sort_3way(int array[],int l,int r)
{
	int pivot;

#if 0
	if(l >= r)
	{
		return ;
	}
#else
	if(r-l <= 7)
	{
		insert_sort(array+l,r-l+1);//在小规模数据的时候使用插入排序
		return;
	}
#endif

	//partition

	swap(array, l,rand()%(r-l+1)+l);
	pivot = array[l];

	int lt = l;//array[l+1...lt]<v
	int gt = r + 1;//array[gt...r]>v
	int i = l + 1;//array[lt+1...i]==v
	while(i < gt)
	{
		if(array[i] < pivot)
		{
			swap(array, i,lt+1);
			lt++;
			i++;
		}
		else if(array[i] > pivot)
		{
			swap(array, i,gt-1);
			gt--;
		}
		else
		{
			i++;
		}
	}
	swap(array, l,lt);
	
	__quick_sort_3way(array,l,lt-1);	
	__quick_sort_3way(array,gt,r);
	return ;
}

void quick_sort_3way(int array[],int len)
{
	srand(time(NULL));
	__quick_sort_3way(array,0,len-1);
}


//=====================================================================
//对array[l...r]部分进行Partision操作
//返回一个索引位置index使得array[l...index-1]<array[index],array[index+1...r]>array[index]
//在面临有重复元素的时候效率低
int __parition(int array[],int l,int r)
{
	int pivot;
	int j = l;

	swap(array, l,rand()%(r-l+1)+l);
	pivot = array[l];
	for(int i = l+1; i <= r; i++)
	{
		if(array[i] < pivot)
		{
			swap(array,j+1, i);
			j++;
		}
	}

	swap(array,l,j);
	return j;
}

void __quick_sort(int array[],int l,int r)
{
	int pivot;

#if 0
	if(l >= r)
	{
		return ;
	}
#else
	if(r-l <= 7)
	{
		insert_sort(array+l,r-l+1);//在小规模数据的时候使用插入排序
		return;
	}
#endif

	
	pivot = __parition(array,l,r);
	__quick_sort(array,l,pivot-1);
	__quick_sort(array,pivot+1,r);
	
	return;
}

void quick_sort(int array[],int len)
{
	srand(time(NULL));
	__quick_sort(array,0,len-1);
}

//todo利用快速排序求第n大的元素

