#include "../includes/pipex.h"

void	error_message(int flag)
{
	if (flag == 1)
		ft_putstr_fd("argc error\n", 2);
	else if (flag == 3)
		ft_putstr_fd("pipe creation error\n", 2);
	else if (flag == 4)
		ft_putstr_fd("fork error\n", 2);
	else if (flag == 7)
		ft_putstr_fd("waitpid error\n", 2);
	else if (flag == 8)
		ft_putstr_fd("success\n", 2);
	exit(EXIT_FAILURE);
}

void	error_message_free(t_pipex *pipex, int flag)
{
	if (flag == 2)
		ft_putstr_fd("command error\n", 2);
	else if (flag == 5)
		ft_putstr_fd("fd error\n", 2);
	else if (flag == 6)
		ft_putstr_fd("execve error\n", 2);
	free_all(pipex);
	exit(EXIT_FAILURE);
}