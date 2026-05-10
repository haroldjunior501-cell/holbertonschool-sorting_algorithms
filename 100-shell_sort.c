#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort with the Knuth sequence
 * @array: the array to sort
 * @size: number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t i;
	size_t j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap * 3 + 1 < size)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
