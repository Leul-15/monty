#include "monty.h"
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * in a doubly linked list
 * @head: double pointer to the list
 * @index: index of the node to insert
 * @num: data to insert
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int index, int num)
{
	unsigned int i;
	dlistint_t *new;
	dlistint_t *temp = *head;

	if (index == 0)
		return (add_dnodeint(head, num));

	for (i = 0; temp && i < index; i++)
	{
		if (i == index - 1)
		{
			if (temp->next == NULL)
				return (add_dnodeint_end(head, num));
			new = malloc(sizeof(dlistint_t));
			if (!new || !head)
				return (NULL);
			new->n = num;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the list
 * @num: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int num)
{
	dlistint_t *new;
	dlistint_t *temp = *head;

	if (!head)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = num;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return (new);
}

/**
 * free_dlistint - frees a doubly linked list
 * @head: pointer to the list to free
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *new;

	while (head)
	{
		new = head->next;
		free(head);
		head = new;
	}
}
