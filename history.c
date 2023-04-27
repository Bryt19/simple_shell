#include "shell.h"

/**
 * get_history_file - gets history file
 * @info: parameter struct
 *
 * Return: designated string containing history file
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
if (!dir)
	return (NULL);
buf = malloc(sizeof(cgar) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buf)
	return (NULL);
buf[0] = 0;
strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
return (buf);
}

/**
 * Write_history - creates a file, or apends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */

int Write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history->file(info);

	if (!filename)
		return (-1);

	fd = open(filename, O_CREATE | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n'. fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - reads history
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */

int read_history(info_t *info)
{
	int zk, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filname = get_history_file(info);

	if (!filename)
		return (0);

	fd = openfilename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (zk = 0; zk < fsize; zk++)
		if (buf[zk] == '\n')
		{
			buf[zk] = 0;
			build_history_list(info, buf + last, linecount++);
			last = zk + 1;
		}
	if (last != zk)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. For maintaining
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0 and 1 if error
 */

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after the changes
 * @info: Structure having potential arguments. used to maintain
 * Return: the new histcount
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int zk = 0;

	while (node)
	{
		node->num = zk++;
		node = node->next;
	}
	return (info->histcount = zk);
}
