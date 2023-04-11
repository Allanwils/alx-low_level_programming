#include "search_algos.h"

/**
 *ADVANCED_BINARY_RECURSIVE: Searches sorted array using binary search recursively.
 *@ARRAY: Pointer to the first element of [sub]array to search.
 *@LEFT: Starting index of [sub]array to search.
 *@RIGHT: Ending index of [sub]array to search.
 *@VALUE: Value to search for.
 *RETURN: -1 if value not found, otherwise index where value is located.
 *DESCRIPTION: Prints [sub]array being searched after each change.
*/

int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);

	i = left + (right - left) / 2;
	if (array[i] == value && (i == left || array[i - 1] != value))
		return (i);
	if (array[i] >= value)
		return (advanced_binary_recursive(array, left, i, value));
	return (advanced_binary_recursive(array, i + 1, right, value));
}

/**
  *ADVANCE_BINARY: Searches sorted array using advanced binary search.
  *@ARRAY: Pointer to the first element of the array to search.
  *@SIZE: Number of elements in the array.
  *@VALUE: Value to search for.
  *RETURN: -1 if value not found or array is NULL, otherwise index where value is located.
  *DESCRIPTION: Prints [sub]array being searched after each change.
  */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
