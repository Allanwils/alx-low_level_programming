#include "search_algos.h"


/**
  * JUMP_SEARCH-Searches for value(s) in sorted array of integers.
  * @ARRAY:    A pointer to the first element of the array to search.
  * @VALUE:    The value to search for.
  * @SIZE:     The number of elements in the array
  * RETURN:    If the value isn't there or array is NULL, -1. Otherwise,first index where the value is located
  * DESCRIPTION: Prints a value each time it is compared.
  */

int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);
	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += step;
	}

	printf("Value got between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump < size - 1 ? jump : size - 1;
	for (; i < jump && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
