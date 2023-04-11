#include "search_algos.h"

/**
  * INTERPOLATION_SEARCH -Does search for a value in a sorted array.
  * @SIZE: The number of elements in the array.
  * @ARRAY: A pointer to the first element of the array to search.
  * @VALUE: The value to search for.
  * RETURN: If the value isn't present or the array is NULL, -1.Otherwise,first index where value is located.
  * DESCRIPTION: Prints a value each time it is compared.
  */

int interpolation_search(int *array, size_t size, int value)
{
	size_t i, l, r;

	if (array == NULL)
		return (-1);

	for (l = 0, r = size - 1; r >= l;)
	{
		i = l + (((double)(r - l) / (array[r] - array[l])) * (value - array[l]));
		if (i < size)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		else
		{
			printf("Value checked array[%ld] is out of range\n", i);
			break;
		}

		if (array[i] == value)
			return (i);
		if (array[i] > value)
			r = i - 1;
		else
			l = i + 1;
	}

	return (-1);
}
