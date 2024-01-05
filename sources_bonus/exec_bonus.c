/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:48:41 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/05 18:21:07 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	exec_cmds(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nbr_of_cmds)
	{
		if (pipe(pipex->fd_pipe) < 0)
			error_message_exit(pipex, 4);
		pipex->cmds_str[i].pid = fork();
		if (pipex->cmds_str[i].pid < 0)
			error_message_exit(pipex, 5);
		if (pipex->cmds_str[i].pid == 0)
			exec_child(pipex, i);
		else
		{
			dup2(pipex->fd_pipe[0], STDIN_FILENO);
			close_pipe_and_fdin(pipex);
			waitpid(pipex->cmds_str[i].pid, &pipex->exit_status, 0);
			get_exit_status(pipex);
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
	if (pipex->fd_in < 0)
	{
		close_all(pipex);
		free_all(pipex, i);
	}
	dup2(pipex->fd_in, STDIN_FILENO);
	close(pipex->fd_pipe[0]);
	dup2(pipex->fd_pipe[1], STDOUT_FILENO);
	close(pipex->fd_pipe[1]);
	if (!pipex->cmds_str[i].cmd_path)
		pipex->exit_status = 127;
	else
		execve(pipex->cmds_str[i].cmd_path, pipex->cmds_str[i].cmd, NULL);
	close_all(pipex);
	free_all(pipex, i);
}

void	exec_mediate(t_pipex *pipex, int i)
{
	close(pipex->fd_pipe[0]);
	dup2(pipex->fd_pipe[1], STDOUT_FILENO);
	close(pipex->fd_pipe[1]);
	if (!pipex->cmds_str[i].cmd_path)
		pipex->exit_status = 127;
	else
		execve(pipex->cmds_str[i].cmd_path, pipex->cmds_str[i].cmd, NULL);
	close_all(pipex);
	free_all(pipex, i);
}

void	exec_final(t_pipex *pipex, int i)
{
	if (pipex->fd_out < 0)
	{
		close_all(pipex);
		free_all(pipex, i);
	}
	dup2(pipex->fd_out, STDOUT_FILENO);
	close(pipex->fd_pipe[1]);
	close(pipex->fd_pipe[0]);
	if (!pipex->cmds_str[i].cmd_path)
		pipex->exit_status = 127;
	else
		execve(pipex->cmds_str[i].cmd_path, pipex->cmds_str[i].cmd, NULL);
	close_all(pipex);
	free_all(pipex, i);
}
