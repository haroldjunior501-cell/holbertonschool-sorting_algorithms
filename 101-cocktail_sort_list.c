#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes (a before b) in a doubly linked list
 * @list: pointer to the head pointer
 * @a: the left node
 * @b: the right node (= a->next)
 */
static void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a = a->prev;
	listint_t *next_b = b->next;

	b->prev = prev_a;
	if (prev_a)
		prev_a->next = b;
	else
		*list = b;
	b->next = a;
	a->prev = b;
	a->next = next_b;
	if (next_b)
		next_b->prev = a;
}

/**
 * forward_pass - one left-to-right bubble pass
 * @list: pointer to the head pointer
 * @left: left boundary node (start after it), or NULL for head
 * @right: pointer to right boundary node (stop before it)
 *
 * Return: 1 if any swap occurred, 0 otherwise
 */
static int forward_pass(listint_t **list, listint_t *left, listint_t **right)
{
	listint_t *cur;
	int swapped;

	swapped = 0;
	cur = left ? left->next : *list;
	while (cur->next != *right)
	{
		if (cur->n > cur->next->n)
		{
			swap_nodes(list, cur, cur->next);
			print_list(*list);
			swapped = 1;
		}
		else
			cur = cur->next;
	}
	*right = cur;
	return (swapped);
}

/**
 * backward_pass - one right-to-left bubble pass
 * @list: pointer to the head pointer
 * @left: pointer to left boundary node (stop before it), or NULL for head
 * @right: right boundary node (start before it)
 *
 * Return: 1 if any swap occurred, 0 otherwise
 */
static int backward_pass(listint_t **list, listint_t **left, listint_t *right)
{
	listint_t *cur;
	int swapped;

	swapped = 0;
	cur = right->prev;
	while (cur->prev != *left)
	{
		if (cur->prev->n > cur->n)
		{
			swap_nodes(list, cur->prev, cur);
			print_list(*list);
			swapped = 1;
		}
		else
			cur = cur->prev;
	}
	*left = cur;
	return (swapped);
}

/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail shaker sort
 * @list: pointer to the head pointer of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left;
	listint_t *right;

	if (!list || !*list || !(*list)->next)
		return;
	left = NULL;
	right = NULL;
	while (forward_pass(list, left, &right))
	{
		if (!backward_pass(list, &left, right))
			break;
	}
}
