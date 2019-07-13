#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#if 0
   int n = 5000000;

    // 测试1 一般性测试
	printf("Test for Random Array, size = %d, random range [0,%d]\n",n,n);
    int* arr1 = generate_random_array(n,0,n);
    int* arr2 = copy_intarray(arr1, n);
    int* arr3 = copy_intarray(arr1, n);
	int* arr4 = copy_intarray(arr1, n);

   // test_sort_func("insertionsort:",insertionsort, arr1, n);
    test_sort_func("mergesortBU:",mergesortBU,arr2, n);
    test_sort_func("mergesort:",mergesort,arr3, n);
	test_sort_func("mergesort2:",mergesort2,arr4,n);

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);
    
    // 测试2 测试近乎有序的数组
    int swapTimes = 10;
    printf("Test for Random Nearly Ordered Array, size = %d,swap time = %d\n",n,swapTimes);
    arr1 = generate_nearly_orderedarray(n,swapTimes);
    arr2 = copy_intarray(arr1, n);
    arr3 = copy_intarray(arr1, n);
	arr4 = copy_intarray(arr1, n);
 
    //test_sort_func("insertionsort:", insertionsort, arr1, n);
    test_sort_func("mergesortBU:",mergesortBU,arr2, n);
    test_sort_func("mergesort:",mergesort,arr3, n);
	test_sort_func("mergesort2:",mergesort2,arr4,n);

    free(arr1);
    free(arr2);
    free(arr3);
	free(arr4);
#endif

void test_sort_perform_o2()
{
	int n = 10000;

	// 测试1 一般性测试
	int* arr1 = generate_random_array(n,0,n);
    int* arr2 = copy_intarray(arr1, n);
    int* arr3 = copy_intarray(arr1, n);
    int* arr4 = copy_intarray(arr1, n);

	printf("Test for Random Array, size = %d, random range [0,%d]\n",n,n);
	test_sort_func("bubble_sort:",bubble_sort, arr1, n);	
	test_sort_func("select_sort:",select_sort, arr2, n);	
	test_sort_func("insert_sort:",insert_sort, arr3, n);	
	test_sort_func("shell_sort:",shell_sort, arr4, n);	
	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	 
	// 测试2 测试近乎有序的数组
	int swapTimes = 10;
	arr1 = generate_nearly_orderedarray(n,swapTimes);
    arr2 = copy_intarray(arr1, n);
    arr3 = copy_intarray(arr1, n);
    arr4 = copy_intarray(arr1, n);

	printf("Test for Random Nearly Ordered Array, size = %d,swap time = %d\n",n,swapTimes);
	test_sort_func("bubble_sort:", bubble_sort, arr1, n);	
	test_sort_func("select_sort:", select_sort, arr2, n);	
	test_sort_func("insert_sort:", insert_sort, arr3, n);	
	test_sort_func("shell_sort:", shell_sort, arr4, n);	
	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);

	return ;	
}

void test_sort_perform()
{
	int n = 1000000;

	// 测试1 一般性测试
	int* arr1 = generate_random_array(n,0,n);
    int* arr2 = copy_intarray(arr1, n);
    int* arr3 = copy_intarray(arr1, n);
    int* arr4 = copy_intarray(arr1, n);

	printf("Test for Random Array, size = %d, random range [0,%d]\n",n,n);
	test_sort_func("shell_sort:", shell_sort, arr1, n);
	test_sort_func("merge_sort:", merge_sort, arr2, n);
	test_sort_func("merge_sortBU:", merge_sortBU, arr3, n);
	test_sort_func("quick_sort:", quick_sort, arr4, n);
	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);

	// 测试2 测试近乎有序的数组
	int swapTimes = 10;
	arr1 = generate_nearly_orderedarray(n,swapTimes);
    arr2 = copy_intarray(arr1, n);
    arr3 = copy_intarray(arr1, n);
    arr4 = copy_intarray(arr1, n);

	printf("Test for Random Nearly Ordered Array, size = %d,swap time = %d\n",n,swapTimes);
	test_sort_func("shell_sort:", shell_sort, arr1, n);	
	test_sort_func("merge_sort:", merge_sort, arr2, n);
	test_sort_func("merge_sortBU:", merge_sortBU, arr3, n);
	test_sort_func("quick_sort:", quick_sort, arr4, n);
	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);

	return ;	
}


void test_quick_sort_perform()
{
	int n = 1000000;

	// 测试1 一般性测试
	int* arr1 = generate_random_array(n,0,n);
    int* arr2 = copy_intarray(arr1, n);
    int* arr3 = copy_intarray(arr1, n);

	printf("Test for Random Array, size = %d, random range [0,%d]\n",n,n);
	test_sort_func("quick_sort:", quick_sort, arr1, n);
	test_sort_func("quick_sort2:", quick_sort2, arr2, n);
	test_sort_func("quick_sort_3way:", quick_sort_3way, arr3, n);
	free(arr1);
	free(arr2);
	free(arr3);

	// 测试2 测试近乎有序的数组
	int swapTimes = 10;
	arr1 = generate_nearly_orderedarray(n,swapTimes);
    arr2 = copy_intarray(arr1, n);
    arr3 = copy_intarray(arr1, n);

	printf("Test for Random Nearly Ordered Array, size = %d,swap time = %d\n",n,swapTimes);
	test_sort_func("quick_sort:", quick_sort, arr1, n);
	test_sort_func("quick_sort2:", quick_sort2, arr2, n);	
	test_sort_func("quick_sort_3way:", quick_sort_3way, arr2, n);	
	free(arr1);
	free(arr2);
	free(arr3);

	arr1 = generate_random_array(n,0,10);
    arr2 = copy_intarray(arr1, n);
    arr3 = copy_intarray(arr1, n);
	
	printf("Test for Small Range Array, size = %d\n",n);
//	test_sort_func("quick_sort:", quick_sort, arr1, n);
	test_sort_func("quick_sort2:", quick_sort2, arr2, n);
	test_sort_func("quick_sort_3way:", quick_sort_3way, arr2, n);	

	
	free(arr1);
	free(arr2);
	free(arr3);

	return ;	
}

void debug_sort()
{
	test_sort_func2(10,quick_sort);
}

int test_sort(void)
{
	debug_sort();
	test_quick_sort_perform();
	return 0;
}
