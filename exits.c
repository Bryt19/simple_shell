#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string in the log
 */
char *_strncpy(char *dest, char *src, int n)
{
	int zk, j;
	char *s = dest;

	zk = 0;
	while (src[zk] != '\0' && zk < n - 1)
	{
		dest[zk] = src[zk];
		zk++;
	}
	if (zk < n)
	{
		j = zk;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string in the log
 */
char *_strncat(char *dest, char *src, int n)
{
	int d, e;
	char *s = dest;

	d = 0;
	e = 0;
	while (dest[d] != '\0')
		d++;
	while (src[e] != '\0' && e < n)
	{
		dest[d] = src[e];
		d++;
		e++;
	}
	if (e < n)
		dest[d] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
