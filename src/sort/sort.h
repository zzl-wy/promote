#ifndef __SORT_H__
#define __SORT_H__

void swap(int array[],int src,int dst);
int* generate_random_array(int n, int range_l, int range_r);
int* generate_nearly_orderedarray(int n, int swapTimes);
int *copy_intarray(int a[], int n);
int issorted(int arr[], int n);
void print_array(int array[],int len);

void test_sort_func(const char* sort_name, void (*sort)(int*, int), int arr[], int n);
void test_sort_func2(int n,void (*sort)(int*, int));

void bubble_sort(int array[],int len);
void select_sort(int array[],int len);
void insert_sort(int array[],int len);

#endif //__SORT_H__
