/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:48:41 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/03 13:28:29 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec_cmds(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nbr_of_cmds)
	{
		if (pipe(pipex->fd_pipe) < 0)
			error_message(pipex, 4);
		pipex->cmds_str[i].pid = fork();
		if (pipex->cmds_str[i].pid < 0)
			error_message(pipex, 5);
		if (pipex->cmds_str[i].pid == 0)
			exec_child(pipex, i);
		else
		{
			dup2(pipex->fd_pipe[0], STDIN_FILENO);
			close(pipex->fd_pipe[0]);
			close(pipex->fd_pipe[1]);
			close(pipex->fd_in);
			waitpid(pipex->cmds_str[i].pid, &pipex->exit_status, WNOHANG);
		}
		free_cmd_array(pipex->cmds_str[i]);
		i++;
	}
	close_all(pipex);
	free_all(pipex, i);
}

void	exec_child(t_pipex *pipex, int i)
{
	if (pipex->cmds_str[i].cmd_position == 'I')
		exec_initial(pipex, i);
	else if (pipex->cmds_str[i].cmd_position == 'M')
		exec_mediate(pipex, i);
	else if (pipex->cmds_str[i].cmd_position == 'F')
		exec_final(pipex, i);
}

void	exec_initial(t_pipex *pipex, int i)
{
	dup2(pipex->fd_in, STDIN_FILENO);
	close(pipex->fd_pipe[0]);
	dup2(pipex->fd_pipe[1], STDOUT_FILENO);
	close(pipex->fd_pipe[1]);
	if (execve(pipex->cmds_str[i].cmd_path, pipex->cmds_str[i].cmd, NULL) < 0)
	{
		close_all(pipex);
		free_all(pipex, i);
	}
}

void	exec_mediate(t_pipex *pipex, int i)
{
	close(pipex->fd_pipe[0]);
	dup2(pipex->fd_pipe[1], STDOUT_FILENO);
	close(pipex->fd_pipe[1]);
	if (execve(pipex->cmds_str[i].cmd_path, pipex->cmds_str[i].cmd, NULL) < 0)
	{
		close_all(pipex);
		free_all(pipex, i);
	}
}

void	exec_final(t_pipex *pipex, int i)
{
	dup2(pipex->fd_out, STDOUT_FILENO);
	close(pipex->fd_pipe[1]);
	close(pipex->fd_pipe[0]);
	if (execve(pipex->cmds_str[i].cmd_path, pipex->cmds_str[i].cmd, NULL) < 0)
	{
		close_all(pipex);
		free_all(pipex, i);
	}
}
