/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:49:12 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/02 14:37:01 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error_message(t_pipex *pipex, int flag)
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
	exit(pipex->exit_status);
}

void	error_message_file(t_pipex *pipex, int flag)
{
	if (flag == 1)
		perror("Error, file not found");
	if (flag == 2)
		perror("Error, cannot read file");
	if (flag == 3)
		perror("Error, cannot open file");
	exit(pipex->exit_status);
}

void	error_message_free(t_pipex *pipex, int flag)
{
	if (flag == 6)
		ft_putstr_fd("cannot get command path\n", 2);
	close_all(pipex);
	free_all(pipex, 0);
}

void	close_all(t_pipex *pipex)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(pipex->fd_in);
	close(pipex->fd_out);
}
