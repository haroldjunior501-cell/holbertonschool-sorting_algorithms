#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection sort
 * @array: the array to sort
 * @size: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min_idx;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
