#ifndef LISTS_H
#define LISTS_H

#include "monty.h"

/* list_function1.c */
size_t dlistint_len(const dlistint_t *head);
dlistint_t *add_dnodeint(dlistint_t **head, const int num);
size_t print_dlistint(const dlistint_t *head);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

/* list_function2.c */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head, unsigned int index, int num);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int num);
void free_dlistint(dlistint_t *head);

#endif
