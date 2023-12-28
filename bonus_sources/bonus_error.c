#include "../includes/bonus_pipex.h"

void	error_message(int flag)
{
	if (flag == 1)
		ft_putstr_fd("invalid parameter usage\n", 2);
	else if (flag == 2)
		ft_putstr_fd("cannot initialize commands\n", 2);
	else if (flag == 3)
		ft_putstr_fd("cannot open file\n", 2);
	exit(EXIT_FAILURE);
}