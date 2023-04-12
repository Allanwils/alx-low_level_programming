#include "search_algos.h"

int recurse_helper(int *array, size_t left,
size_t right, int value, ssize_t *match);

/**
 * advanced_binary - searches for a value in an array of sorted integers
 * @array: array to search for.
 * @size: size of the  array.
 * @value: value to search for.
 *
 * Return: index of the value found ; otherwise -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	ssize_t match = -1;

	if (array == NULL)
		return (-1);

	return (recurse_helper(array, 0, size - 1, value, &match));
}

/**
 * recurse_helper - recursive implementation of binary search
 * @array: array to search for
 * @left:  left index
 * @right: right index
 * @value: value to search for.
 * @match: points to index of the most recent match.
 *
 * Return: index of value found; or otherwise -1 if not found
 */
int recurse_helper(int *array, size_t left,
size_t right, int value, ssize_t *match)
{
	size_t i = left, mid;

	if (left > right)
		return (*match);

	/* print search progress */
	printf("Searching in array: %d", array[i++]);
	while (i <= right)
		printf(", %d", array[i++]);
	printf("\n");

	/* calculate mid */
	mid = left + ((right - left) / 2);

	/* check if mid is value */
	if (array[mid] == value)
	{
		*match = mid;
		if (right - left > 1)
			mid++;
	}
	else if (array[mid] < value) /* search right */
		return (recurse_helper(array, mid + 1, right, value, match));

	if (mid != 0)
		return (recurse_helper(array, left, mid - 1, value, match));
	else
		return (*match);
}
