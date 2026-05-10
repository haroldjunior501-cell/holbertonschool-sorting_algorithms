#include "sort.h"

/**
 * partition - Lomuto partition: pivot = last element
 * @array: the array
 * @size: total size of the array (for printing)
 * @lo: left boundary index
 * @hi: right boundary index (pivot)
 *
 * Return: final index of the pivot
 */
static int partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j;
	int tmp;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != hi)
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - recursive helper for quick_sort
 * @array: the array to sort
 * @size: total size of the array
 * @lo: left boundary of the partition
 * @hi: right boundary of the partition
 */
static void quicksort(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo >= hi)
		return;

	p = partition(array, size, lo, hi);
	quicksort(array, size, lo, p - 1);
	quicksort(array, size, p + 1, hi);
}

/**
 * quick_sort - sorts an array of integers using quick sort
 * @array: the array to sort
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, size, 0, (int)(size - 1));
}
