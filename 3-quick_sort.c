#include "sort.h"

/**
 * swap_int - swaps two integers
 *
 * @a: The first integer
 * @b: The second integer
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partitions an array
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @start: The starting index
 * @end: The ending index
 *
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int start, int end)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_int(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_int(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * rec_sort - sorts an array using recursion
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @start: The starting index
 * @end: The ending index
 *
 * Return: Nothing (void).
 */
void rec_sort(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = partition(array, size, start, end);
		rec_sort(array, size, start, part - 1);
		rec_sort(array, size, part + 1, end);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing (void).
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	rec_sort(array, size, 0, size - 1);
}

