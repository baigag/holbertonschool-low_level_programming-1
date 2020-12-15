#include "lists.h"
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current_node = *h;
	unsigned int count = 0;

	new_node = malloc(sizeof(dlistint_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*h == NULL && idx > 0)
	{
		free(new_node);
		return (NULL);
	}
	if (idx == 0)
	{
		new_node->next = *h;
		*h = new_node;
		if (current_node != NULL)
			current_node->prev = new_node;
		return (new_node);
	}
	for (; count  <= idx; count++)
	{
		if (current_node == NULL)
		{
			free(new_node);
			return (NULL);
		}
		if (count + 1 == idx)
		{
			if (current_node->next != NULL)
				current_node->next->prev = new_node;
			new_node->next = current_node->next;
			current_node->next = new_node;
			new_node->prev = current_node;
			return (new_node);
		}
		current_node = current_node->next;
	}
	return (new_node);
}