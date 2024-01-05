/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:50:37 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/05 18:20:07 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	close_all(t_pipex *pipex)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(pipex->fd_in);
	close(pipex->fd_out);
	close(pipex->fd_pipe[0]);
	close(pipex->fd_pipe[1]);
}

void	close_pipe_and_fdin(t_pipex *pipex)
{
	close(pipex->fd_pipe[0]);
	close(pipex->fd_pipe[1]);
	close(pipex->fd_in);
}
