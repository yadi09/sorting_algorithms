#include "sort.h"

/**
 * bubble_sort - implementation of bubble sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int count;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		count = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp;

				temp = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = temp;
				print_array(array, size);
				count++;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}
