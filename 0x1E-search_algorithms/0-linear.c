#include "search_algos.h"

/**
 * linear_search - searches  for a value in an array of integers .
 * @array: points to the first element of the array to search .
 * @size: number of elements in array.
 * @value: The value to search for.
 * Return: If the value is not present or the array is NULL, -1.
 *   Otherwise, the index of the first occurrence of the value in the array.
 *
 * Description: prints value being compared in the array at each step.
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
