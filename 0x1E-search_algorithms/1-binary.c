#include "search_algos.h"

/**
  * BINARY_SEARCH - Does search for a value(s) in sorted array of integers.
  * @SIZE: number of elements array.
  * @VALUE: The value to search for.
  * @ARRAY: Points to first element of the array.
  * RETURN: If value is missing or array is NULL, -1. Otherwise,index where value is located.
  * DESCRIPTION: Prints array being searched after every change.
  */

int binary_search(int *array, size_t size, int value)
{
	size_t i, left, right;

	if (array == NULL)
		return (-1);

	for (left = 0, right = size - 1; right >= left;)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}
