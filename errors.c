#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int zk = 0;

	if (!str)
		return;
	while (str[zk] != '\0')
	{
		_eputchar(str[zk]);
		zk++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print on log
 *
 * Return: On success 0 and 1 on error.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int zk;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || zk >= WRITE_BUF_SIZE)
	{
		write(2, buf, zk);
		zk = 0;
	}
	if (c != BUF_FLUSH)
		buf[zk++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print on log
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and error is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int zk;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || zk >= WRITE_BUF_SIZE)
	{
		write(fd, buf, zk);
		zk = 0;
	}
	if (c != BUF_FLUSH)
		buf[zk++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put ok
 */
int _putsfd(char *str, int fd)
{
	int z = 0;

	if (!str)
		return (0);
	while (*str)
	{
		z += _putfd(*str++, fd);
	}
	return (z);
}
