#include "shell.h"

/**
 * print_history - Print the list of commands in the history
 * @info: The shell's info struct
 * Return: 0 on success, 1 on error
 */
int print_history(info_t *info)
{
	if (info == NULL || info->history == NULL)
		return (1);

	print_list(info->history);

	return (0);
}

/**
 * unset_alias - Remove an alias from the alias list
 * @info: The shell's info struct
 * @alias: The alias to remove
 * Return: 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *alias)
{
	if (info == NULL || info->alias == NULL || alias == NULL)
		return (1);

	char *eq = _strchr(alias, '=');

	if (eq == NULL)
		return (1);

	*eq = '\0';
	int index = get_node_index(info->alias,
	node_starts_with(info->alias, alias, -1));
	*eq = '=';
	if (index < 0)
		return (1);

	if (delete_node_at_index(&(info->alias), index) == NULL)
		return (1);

	return (0);
}

/**
 * set_alias - Add or update an alias in the alias list
 * @info: The shell's info struct
 * @alias: The alias to set (in the form "name=value")
 * Return: 0 on success, 1 on error
 */
int set_alias(info_t *info, char *alias)
{
	if (info == NULL || alias == NULL)
		return (1);

	char *eq = _strchr(alias, '=');

	if (eq == NULL)
		return (1);

	*eq = '\0';
	if (*++eq == '\0')
		return (unset_alias(info, alias));

	if (unset_alias(info, alias) != 0)
		return (1);

	if (add_node_end(&(info->alias), alias, 0) == NULL)
		return (1);

	return (0);
}

/**
 * print_alias - Print the name and value of an alias
 * @alias_node: The alias to print
 * Return: 0 on success, 1 on error
 */
int print_alias(list_t *alias_node)
{
	if (alias_node == NULL)
		return (1);

	char *eq = _strchr(alias_node->str, '=');

	if (eq == NULL)
		return (1);

	*eq = '\0';
	_puts(alias_node->str);
	*eq = '=';
	_puts(eq + 1);
	_puts("\n");

	return (0);
}

/**
 * _myalias - Add, remove or show aliases
 * @info: The shell's info struct
 * Return: 0 on success, 1 on error
 */
int _myalias(info_t *info)

{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
