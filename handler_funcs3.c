#include "monty.h"
#include "lists.h"

/**
 * rotl_handler - handles the rotl instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void rotl_handler(stack_t **stack, unsigned int line_count)
{
	stack_t *new_node = *stack;
	int num = 0;

	(void)line_count;

	if (*stack == NULL)
		return;
	new_node = get_dnodeint_at_index(*stack, 0);
	num = new_node->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, num);
}

/**
 * rotr_handler - handles the rotr instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void rotr_handler(stack_t **stack, unsigned int line_count)
{
	stack_t *new_node = *stack;
	int num = 0, len = dlistint_len(*stack);

	(void)line_count;

	if (*stack == NULL)
		return;
	new_node = get_dnodeint_at_index(*stack, len - 1);
	num = new_node->n;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, num);
}

/**
 * stack_handler - handles the stack instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void stack_handler(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
	data.qflag = 0;
}

/**
 * queue_handler - handles the queue instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void queue_handler(stack_t **stack, unsigned int line_count)
{
	(void)stack;
	(void)line_count;
	data.qflag = 1;
}
