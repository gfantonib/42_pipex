/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:49:25 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/05 18:22:25 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_all(t_pipex *pipex, int i)
{
	while (i < pipex->nbr_of_cmds)
	{
		free_cmd_array(pipex->cmds_str[i]);
		i++;
	}
	free(pipex->cmds_str);
	if (pipex->fd_out < 0)
		pipex->exit_status = 1;
	exit(pipex->exit_status);
}

void	free_cmd_array(t_cmd cmd_array)
{
	if (cmd_array.cmd_path)
		free(cmd_array.cmd_path);
	if (cmd_array.cmd)
		free_split(cmd_array.cmd);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
