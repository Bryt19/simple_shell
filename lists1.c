#include "shell.h"

/**
 * list_len - finds out length of linked lst
 * @h: pointe to first node
 *
 * Return: size of list
 */

size_t list_len(const lst_t *h)
{
	ssize_t zk = 0;

	while (h)
	{
		h = h->next;
		zk++;
	}
	return (zk);
}

/**
 * list_to_strings - returns an array of strings of th lst->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = mallocd(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - prints every element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */

size_t print_list(const list_t *h)
{
	size_t zk = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n")
			h = h->next;
		zk++;
	}
	return (zk);
}

/**
 * node_starts_with - returns node wich has string starting with prefix
 * @node: pointer to list head
 * @prefix: string i order to match
 * @c: the other character after prefix to match
 *
 * Return: match node pr null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *pk = NULL;

	while (node)
	{
		pk = starts_with(node->str, prefix);
		if (pk && ((c == -1) || (*pk == c)))
			return (node);
		node = node->next;
	}

/**
 * get_node_index - aquires the index of a node
 * @head: pointer to a list head
 * @node: pointer to the node
 *
 * Return: index of the node or -1 if there's an error
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t zk = 0;

	while (head)
	{
		if (head == node)
			return (zk);
		head = head->next;
		zk++;
	}
	return (-1);
}
