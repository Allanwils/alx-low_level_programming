#include "search_algos.h"

int recurse_helper(int *arr, size_t size, int val, size_t idx);

/**
 * linear_search - Linear search for value in integer array
 * @array: points to array of integers
 * @size: size of array
 * @value: value to search for
 *
 * Return: index of value; -1 if value isn't found.
 */
int linear_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (recurse_helper(array, size, value, 0));
}

/**
 * recurse_helper - Recursive implementation of linear search
 * @arr: points to array of integers
 * @size: size of array
 * @val: value to find
 * @idx: current index
 *
 * Return: index of value; -1 if value not found
 */
int recurse_helper(int *arr, size_t size, int val, size_t idx)
{
	if (arr == NULL || (long int)size < 0)
		return (-1);

	for (size_t i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, arr[i]);

		if (arr[i] == val)
		{
			return ((int)i);
		}
	}

	return (recurse_helper(arr, size, val, idx + 1));
}
