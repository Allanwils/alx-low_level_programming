#include "search_algos.h"

skiplist_t *recurse_normal(skiplist_t *probe, skiplist_t *stop, int value);
skiplist_t *recurse_express(skiplist_t *probe, int value);
skiplist_t *find_list_end(skiplist_t *probe);

/**
 * linear_skip - Searches with skip list
 * @list:  search list
 * @value: value to search.
 *
 * Return: the matching node; otherwise NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *zone = NULL;

	if (list == NULL)
		return (NULL);

	zone = recurse_express(list, value);

	if (zone->n == value)
		return (zone);
	else
		return (recurse_normal(zone, zone->express, value));
}
/**
 * recurse_express - search the express list.
 * @probe:  search pointer.
 * @value:  value to search
 *
 * Return:  A pointer to match ; otherwise  NULL if not in range
 */
skiplist_t *recurse_express(skiplist_t *probe, int value)
{
	skiplist_t *last = NULL;

	if (probe->express == NULL)
	{
		last = find_list_end(probe);
		printf("Value found between indexes [%lu] and [%lu]\n",
probe->index, last->index);
		return (probe);
	}

	printf("Value checked at index [%lu] = [%d]\n",
probe->express->index, probe->express->n);

	if (probe->express->n >= value)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
probe->index, probe->express->index);
		return (probe);
	}
	else
		return (recurse_express(probe->express, value));
}
/**
 * recurse_normal - searches normal list
 * @probe: the search pointer
 * @stop: endpoint of the sub-search; express node or NULL
 * @value: value to search
 *
 * Return: a pointer to match; otherwise NULL if not found
 */
skiplist_t *recurse_normal(skiplist_t *probe, skiplist_t *stop, int value)
{
	if (probe == stop)
	{
		if (stop != NULL && stop->n == value)
			return (stop);
		else
			return (NULL);
	}

	printf("Value checked at index [%lu] = [%d]\n",
probe->index, probe->n);

	if (probe->n == value)
		return (probe);
	else
		return (recurse_normal(probe->next, stop, value));
}
/**
 * find_list_end - find the last node.
 * @probe:  the search pointer
 *
 * Return: A pointer to the final node.
 */
skiplist_t *find_list_end(skiplist_t *probe)
{
	if (probe->next == NULL)
		return (probe);
	else
		return (find_list_end(probe->next));
}
