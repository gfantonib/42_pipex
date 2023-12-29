#include "../includes/bonus_pipex.h"

void	error_message(int flag)
{
	if (flag == 1)
		ft_putstr_fd("invalid parameter usage\n", 2);
	else if (flag == 2)
		ft_putstr_fd("cannot initialize commands\n", 2);
	else if (flag == 3)
		ft_putstr_fd("cannot open file\n", 2);
	else if (flag == 4)
		ft_putstr_fd("cannot initialize pipe\n", 2);
	else if (flag == 5)
		ft_putstr_fd("cannot initialize fork\n", 2);
	exit(EXIT_FAILURE);
}

void	error_message_free(t_pipex *pipex, int flag)
{
	if (flag == 6)
		ft_putstr_fd("cannot get command path\n", 2);
	free_all(pipex, 0);
}