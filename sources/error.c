/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:49:12 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/04 13:41:41 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error_message(t_pipex *pipex, int i, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(pipex->cmds_str[i].cmd[0], 2);
		ft_putstr_fd("\n", 2);
	}
}

void	error_message_exit(t_pipex *pipex, int flag)
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
