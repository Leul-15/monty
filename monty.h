#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct args_s - structure of arguments from main
 * @argv: name of the file from the command line
 * @argc: number of arguments from main
 * @line_count: number of the current line in the file
 *
 * Description: arguments passed to main from the command line
 * used in different functions, organized in a struct for clarity
 */
typedef struct args_s
{
	char *argv;
	int argc;
	unsigned int line_count;
} args_t;

/**
 * struct data_s - extern data to access inside functions
 * @line: line from the file
 * @word: parsed line
 * @stack: pointer to the stack
 * @fpt: file pointer
 * @qflag: flag for queue or stack
 */
typedef struct data_s
{
	char *line;
	char **word;
	stack_t *stack;
	FILE *fpt;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT                 \
	{                             \
		NULL, NULL, NULL, NULL, 0 \
	}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

/* main.c */
void monty_function(args_t *args);

/* char_function.c */
void pchar_handler(stack_t **stack, unsigned int line_count);
void pstr_handler(stack_t **stack, unsigned int line_count);

/* get_function.c */
void (*get_func(char **parsed))(stack_t **, unsigned int);
void push_handler(stack_t **stack, unsigned int line_count);
void pall_handler(stack_t **stack, unsigned int line_count);

/* handler_function1.c */
void pint_handler(stack_t **stack, unsigned int line_count);
void pop_handler(stack_t **stack, unsigned int line_count);
void swap_handler(stack_t **stack, unsigned int line_count);
void nop_handler(stack_t **stack, unsigned int line_count);
void add_handler(stack_t **stack, unsigned int line_count);

/* handler_function2.c */
void sub_handler(stack_t **stack, unsigned int line_count);
void mul_handler(stack_t **stack, unsigned int line_count);
void div_handler(stack_t **stack, unsigned int line_count);
void mod_handler(stack_t **stack, unsigned int line_count);

/* handler_functin3.c */
void rotl_handler(stack_t **stack, unsigned int line_count);
void rotr_handler(stack_t **stack, unsigned int line_count);
void stack_handler(stack_t **stack, unsigned int line_count);
void queue_handler(stack_t **stack, unsigned int line_count);

/* strtow.c */
int count_word(char *str);
char **strtow(char *str);
void free_everything(char **args);

/* free_function.c */
void free_all(int all);

#endif
