#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Nothing (void).
 */
void bubble_sort(int *array, size_t size)
{
	int flag = 1;
	int tmp = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;

	while (flag == 1)
	{
		flag = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				/* Swap the two integers */
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
	}
}
