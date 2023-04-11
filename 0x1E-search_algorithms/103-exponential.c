#include "search_algos.h"

/**
  * _BINARY_SEARCH - Uses binary to search.
  * @ARRAY:  Points to the first element of the array.
  * @LEFT:   Starting index
  * @RIGHT:  Ending index
  * @VALUE:  Value to search for.
  * RETURN: NULL, -1, otherwwise the index where the value is located.
  */

int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (right >= left)
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

/**
*  EXPONENTIAL_SEARCH -Uses exponential search.
  * @ARRAY:Points to first element of the array.
  * @SIZE: Size of array.
  * @SIZE: Value to search for.
  *
  * RETURN: NULL, -1, otherwise index where the value is located.
  */

int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	if (i < size)
		right = i;
	else
		right = size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (_binary_search(array, i / 2, right, value));
}
