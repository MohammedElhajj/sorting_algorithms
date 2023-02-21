#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using using the Selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Nothing (void).
 */
void selection_sort(int *array, size_t size)
{
	int flag, tmp, place;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		flag = 0;
		tmp = 0;
		for (j = i + 1; j < size; j++)
		{
			if (!flag && array[j] < array[i])
			{
				tmp = array[j];
				place = j;
				flag = 1;
			}
			if (flag && array[j] < tmp)
			{
				tmp = array[j];
				place = j;
			}
		}
		if (flag)
		{
			array[place] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
