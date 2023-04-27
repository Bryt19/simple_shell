#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int zk = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[zk])
	{
		dest[zk] = src[zk];
		zk++;
	}
	dest[zk] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *rekt;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	rekt = malloc(sizeof(char) * (length + 1));
	if (!rekt)
		return (NULL);
	for (length++; length--;)
		rekt[length] = *--str;
	return (rekt);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing in the code
 */
void _puts(char *str)
{
	int zk = 0;

	if (!str)
		return;
	while (str[zk] != '\0')
	{
		_putchar(str[zk]);
		zk++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1 or 0 if error.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int zk;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || zk >= WRITE_BUF_SIZE)
	{
		write(1, buf, zk);
		zk = 0;
	}
	if (c != BUF_FLUSH)
		buf[zk++] = c;
	return (1);
}
