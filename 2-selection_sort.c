#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 *
 * Implements the selection sort algorithm, a simple comparison
 *  sorting technique.
 * The algorithm divides the input array into a sorted and an unsorted segment.
 * It repeatedly selects the smallest (or largest) element
 *  from the unsorted segment
 * and moves it to the end of the sorted segment.
 *  The process involves two nestedloops
 * The outer loop traverses from the start of the array, and the
 *  inner loop finds
 * the minimum element in the unsorted part of the array.
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int temp = 0;
	size_t current_i;
	/*Index of the currently found minimum element*/
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		current_i = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[current_i] > array[j])
				current_i = j;
		}
		/* swap if smaller elem is found*/
		if (current_i != i)
		{
			temp = array[i];
			array[i] = array[current_i];
			array[current_i] = temp;
			print_array(array, size);
		}
	}
}
