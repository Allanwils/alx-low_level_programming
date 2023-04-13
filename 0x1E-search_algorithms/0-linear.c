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

	if (arr[idx] == val)
	{
		return ((int)idx);
	}
	else if (idx == size - 1)
	{
		return (-1);
	}
	
}
