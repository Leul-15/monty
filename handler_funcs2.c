#include "monty.h"
#include "lists.h"

/**
 * sub_handler - handles the sub instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void sub_handler(stack_t **stack, unsigned int line_count)
{
	int sub = 0;
	stack_t *new = NULL;
	stack_t *new_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	sub = new_1->n - new_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new = add_dnodeint(stack, sub);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mul_handler - handles the mul instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void mul_handler(stack_t **stack, unsigned int line_count)
{
	int mul = 0;
	stack_t *new = NULL;
	stack_t *new_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mul = new_1->n * new_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new = add_dnodeint(stack, mul);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * div_handler - handles the div instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void div_handler(stack_t **stack, unsigned int line_count)
{
	int div = 0;
	stack_t *new = NULL;
	stack_t *new_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, DIV_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (new_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	div = new_1->n / new_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new = add_dnodeint(stack, div);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}

/**
 * mod_handler - handles the mod instruction
 * @stack: double pointer to the stack to push to
 * @line_count: number of the line in the file
 */
void mod_handler(stack_t **stack, unsigned int line_count)
{
	int mod = 0;
	stack_t *new = NULL;
	stack_t *new_0 = get_dnodeint_at_index(*stack, 0);
	stack_t *new_1 = get_dnodeint_at_index(*stack, 1);

	if (dlistint_len(*stack) < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	if (new_0->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, line_count);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	mod = new_1->n % new_0->n;
	delete_dnodeint_at_index(stack, 0);
	delete_dnodeint_at_index(stack, 0);
	new = add_dnodeint(stack, mod);
	if (!new)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
