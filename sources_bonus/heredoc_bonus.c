/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:40:53 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/06 14:55:46 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(t_pipex *pipex)
{
	char	*line;
	int		pipe_fd[2];

	line = NULL;
	if (pipe(pipe_fd) < 0)
		error_message_exit(pipex, 4);
	while (1)
	{
		ft_putstr_fd("pipe: here_doc > ", STDIN_FILENO);
		line = get_next_line(STDERR_FILENO);
		if (!ft_strncmp(line, pipex->limiter, ft_strlen(pipex->limiter)))
		{
			free(line);
			free(line); // WTF?
			break ;
		}
		ft_putstr_fd(line, pipe_fd[1]);
		free(line);
	}
	close(pipe_fd[1]);
	pipex->fd_in = pipe_fd[0];
}
