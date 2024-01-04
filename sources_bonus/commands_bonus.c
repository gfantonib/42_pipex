/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:42:09 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/04 10:08:02 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	set_to_null(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nbr_of_cmds)
	{
		pipex->cmds_str[i].cmd = NULL;
		pipex->cmds_str[i].cmd_path = NULL;
		i++;
	}
}

void	get_cmds(t_pipex *pipex, char **argv, char **envp)
{
	int	i;
	int	cmd_index;

	pipex->cmds_str = (t_cmd *)malloc(sizeof(t_cmd) * pipex->nbr_of_cmds);
	if (!pipex->cmds_str)
		error_message_exit(pipex, 2);
	set_to_null(pipex);
	i = 0;
	cmd_index = pipex->cmd_index;
	while (i < pipex->nbr_of_cmds)
	{
		pipex->cmds_str[i].cmd = ft_split(argv[cmd_index], ' ');
		pipex->cmds_str[i].cmd_path = get_path(pipex->cmds_str[i].cmd[0], envp);
		if (!pipex->cmds_str[i].cmd_path)
			error_message(pipex, i, 1);
		pipex->cmds_str[i].pid = -1;
		if (i == 0)
			pipex->cmds_str[i].cmd_position = 'I';
		else if (i < (pipex->nbr_of_cmds - 1))
			pipex->cmds_str[i].cmd_position = 'M';
		else
			pipex->cmds_str[i].cmd_position = 'F';
		cmd_index++;
		i++;
	}
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_split(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_split(paths);
	return (0);
}
