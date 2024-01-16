#include "sort.h"

/**
 * partition - takes the last element of an array as the pivot
 * and places it in its sorted position with all elements to the left smaller
 * and all elements to the right bigger
 * @array: array of integers
 * @low: lowest index in array
 * @high: highest index in array
 * @size: size of entire original array
 *
 * Return: integer index where pivot was placed
 */

int partition(int *array, int low, int high, size_t size)
{
	int i, j, tmp, pivot;

	pivot = array[high];

	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}

	array[high] = array[i + 1];
	array[i + 1] = pivot;
	if (array[high] != pivot)
		print_array(array, size);

	return (i + 1);
}

/**
 * recursive - recursive quicksort algorithm
 * @array: int array to be partitioned and sorted
 * @low: index where sub-array to be sorted starts
 * @high: index where sub-array to be sorted ends
 * @size: size of entire original array
 *
 * Return: No return value
 */

void recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		recursive(array, low, pivot_index - 1, size);
		recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - driver to run qs_recursive
 * @array: array to be sorted
 * @size: length of array
 *
 * Return: No return value
 */

void quick_sort(int *array, size_t size)
{
	int len, low, high;

	if (array == NULL)
		return;

	len = (int)size;
	low = 0;
	high = len - 1;

	recursive(array, low, high, size);
}
