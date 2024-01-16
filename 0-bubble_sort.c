#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using the
 *               bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: Bubble sort repeatedly steps through the list, compares
 * adjacent elements, and swaps them if they are in the wrong order.
 * The pass through the list is repeated until the list is sorted.
 * This function prints the array after each swap operation.
 */

void bubble_sort(int *array, size_t size)
{
	int temp = 0;
	size_t count, i = 0;

	if (size < 2)
		return;
	/* we dont care if 0 / 1 elements */

	while (size - 1 - i)
	{
		for (count = 0; count < size - 1 - i; count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count + 1];
				array[count + 1] = array[count];
				array[count] = temp;
				print_array(array, size);
				/* print the array after each swap*/
			}
		}
		i++;
	}
}
