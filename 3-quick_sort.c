#include "sort.h"

/**
  * partition - function for partitioning the array
  * @array: the array to be partitioned
  * @lb: lower bound
  * @ub: upperbound
  * @size: size of the array
  *
  * Return: int
  */
int partition(int *array, int lb, int ub, size_t size)
{
	int i, temp, j, pivot;

	pivot = array[ub];

	i = lb - 1;

	for (j = lb; j < ub; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[ub];
	array[ub] = temp;
	print_array(array, size);
	return (i + 1);
}
/**
  * quick_lomuto - quick sort algorithm implementation
  * @array: array to be sorted
  * @lb: lower bound
  * @ub: upper bound
  * @size: size of the array
  */
void quick_lomuto(int *array, int lb, int ub, size_t size)
{
	int pivot;

	if (lb < ub)
	{
		pivot = partition(array, lb, ub, size);
		quick_lomuto(array, lb, pivot - 1, size);
		quick_lomuto(array, pivot + 1, ub, size);
	}
}
/**
  * quick_sort - quick sort algorithm
  * @array: array to be sorted
  * @size: size of the array
  */
void quick_sort(int *array, size_t size)
{
	quick_lomuto(array, 0, size - 1, size);
}
