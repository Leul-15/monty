#include "monty.h"
#include "lists.h"

/**
 * count_word - helper function to count the number of words in a string
 * @str: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *str)
{
	int flag, n, n1;

	flag = 0;
	n1 = 0;

	for (n = 0; str[n] != '\0'; n++)
	{
		if (str[n] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			n1++;
		}
	}

	return (n1);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
	char **mtrx, *new;
	int n, count = 0, len = 0, word, c = 0, head, tail;

	len = strlen(str);
	word = count_word(str);
	if (word == 0)
		return (NULL);

	mtrx = (char **)malloc(sizeof(char *) * (word + 1));
	if (mtrx == NULL)
		return (NULL);

	for (n = 0; n <= len; n++)
	{
		if (isspace(str[n]) || str[n] == '\0' || str[n] == '\n')
		{
			if (c)
			{
				tail = n;
				new = (char *)malloc(sizeof(char) * (c + 1));
				if (new == NULL)
					return (NULL);
				while (head < tail)
					*new++ = str[head++];
				*new = '\0';
				mtrx[count] = new - c;
				count++;
				c = 0;
			}
		}
		else if (c++ == 0)
			head = n;
	}

	mtrx[count] = NULL;

	return (mtrx);
}

/**
 * free_everything - frees arrays of strings
 * @args: array of strings to free
 */
void free_everything(char **args)
{
	int n;

	if (!args)
		return;

	for (n = 0; args[n]; n++)
		free(args[n]);

	free(args);
}
