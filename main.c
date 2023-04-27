#include "shell.h"

/**
 * main - Contains all the headers file
 * @ac: Argument counter used
 * @av: Argument vector used
 *
 * Return: 0 if its success and 1 if error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fdk = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fdk)
			: "r" (fdk));

	if (ac == 2)
	{
		fdk = open(av[1], O_RDONLY);
		if (fdk == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fdk;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
