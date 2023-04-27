#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int arb, sol, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (arb = 0; str[arb] != '\0'; arb++)
		if (!is_delim(str[arb], d) && (is_delim(str[arb + 1], d) || !str[arb + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (arb = 0, sol = 0; sol < numwords; sol++)
	{
		while (is_delim(str[arb], d))
			arb++;
		k = 0;
		while (!is_delim(str[arb + k], d) && str[arb + k])
			k++;
		s[sol] = malloc((k + 1) * sizeof(char));
		if (!s[sol])
		{
			for (k = 0; k < sol; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[sol][m] = str[arb++];
		s[sol][m] = 0;
	}
	s[sol] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL
 */
char **strtow2(char *str, char d)
{
	int zk, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (zk = 0; str[zk] != '\0'; zk++)
		if ((str[zk] != d && str[zk + 1] == d) ||
		    (str[zk] != d && !str[zk + 1]) || str[zk + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (zk = 0, j = 0; j < numwords; j++)
	{
		while (str[zk] == d && str[zk] != d)
			zk++;
		k = 0;
		while (str[zk + k] != d && str[zk + k] && str[zk + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[zk++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
