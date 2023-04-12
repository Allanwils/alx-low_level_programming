#include "search_algos.h"

int recurse_helper(int *arr, size_t size, int val, size_t idx);

/**
 * linear_search - Linear search for value in integer array
 * @array: points to array of integers
 * @size: size of array
 * @value: value to search for
 *
 * Return: index  value; -1 if value isn't found.
 */
int linear_search(int *array, size_t size, int value)
{

	if (array == NULL)
		return (-1);

	return (recurse_helper(array, size, value, 0));
}
/**
 * recurse_helper - recursive implementation of linear search
 * @arr: points to array of integers
 * @size: size of array
 * @val: value to find
 * @idx: current index
 *
 * Return: index value; -1 if value not found
 */
int recurse_helper(int *arr, size_t size, int val, size_t idx)
{
	if (idx == size)
		return (-1);

	printf("Value checked array[%lu] = [%d]\n", idx, arr[idx]);

	if (arr[idx] == val)
		return (idx);

	return (recurse_helper(arr, size, val, idx + 1));
}
