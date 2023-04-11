#include "search_algos.h"

/**
  * JUMP_LIST: Searches sorted singly linked list using jump search.
  * @LIST: Pointer to the head of the linked list to search.
  * @SIZE: Number of nodes in the list.
  * @VALUE: Value to search for.
  * RETURN: NULL if value not found or head of list is NULL, otherwise pointer to first     *    node where value is located.
  * DESCRIPTION: Prints value every time it is compared in the list. Uses square root of    *   list size as jump step.
 */


listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, step_size;
	listint_t *node, *jump;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;
	step_size = sqrt(size);
	for (node = jump = list; jump->index + 1 < size && jump->n < value;)
	{
		node = jump;
		for (step += step_size; jump->index < step; jump = jump->next)
		{
			if (jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jump->index, jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jump->index);

	for (; node->index < jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
