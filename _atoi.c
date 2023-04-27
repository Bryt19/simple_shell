#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode otherwise false
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise that is error
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int k, sign_k = 1, flag_n = 0, output_n;
	unsigned int result_n = 0;

	for (k = 0;  s[k] != '\0' && flag_n != 2; k++)
	{
		if (s[k] == '-')
			sign_k *= -1;

		if (s[k] >= '0' && s[k] <= '9')
		{
			flag_n = 1;
			result_n *= 10;
			result_n += (s[k] - '0');
		}
		else if (flag_n == 1)
			flag_n = 2;
	}

	if (sign_k == -1)
		output_n = -result_n;
	else
		output_n = result_n;

	return (output_n);
}
