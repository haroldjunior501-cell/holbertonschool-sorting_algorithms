#include "sort.h"

/**
 * swap_with_prev - swaps a node with its predecessor in a doubly linked list
 * @list: pointer to the head pointer of the list
 * @node: the node to move one position to the left
 */
static void swap_with_prev(listint_t **list, listint_t *node)
{
	listint_t *p = node->prev;
	listint_t *pp = p->prev;
	listint_t *nx = node->next;

	node->prev = pp;
	if (pp != NULL)
		pp->next = node;
	else
		*list = node;

	node->next = p;
	p->prev = node;

	p->next = nx;
	if (nx != NULL)
		nx->prev = p;
}

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 * @list: pointer to the head pointer of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap_with_prev(list, current);
			print_list(*list);
		}
		current = tmp;
	}
}
