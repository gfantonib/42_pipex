/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:40:50 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/06 12:41:24 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	get_fd_file(t_pipex *pipex, char **argv)
{
	get_file_name(pipex, argv);
	get_fd_input(pipex);
	get_fd_output(pipex);
}

void	get_file_name(t_pipex *pipex, char **argv)
{
	pipex->input_file = argv[1];
	pipex->output_file = argv[pipex->nbr_of_cmds + 2];
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		pipex->nbr_of_cmds--;
		pipex->cmd_index++;
		pipex->has_heredoc = 'T';
		pipex->limiter = argv[2];
		pipex->output_file = argv[pipex->nbr_of_cmds + 3];
	}
}

void	get_fd_input(t_pipex *pipex)
{
	if (pipex->has_heredoc == 'T')
		here_doc(pipex);
	else
	{
		pipex->fd_in = open(pipex->input_file, O_RDONLY);
		if (pipex->fd_in < 0)
			perror("Error, cannot open file");
	}
}

void	get_fd_output(t_pipex *pipex)
{
	if (pipex->has_heredoc == 'T')
	{
		pipex->fd_out = open(pipex->output_file, \
			O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (pipex->fd_out < 0)
			perror("Error, cannot open file");
	}
	else
	{
		pipex->fd_out = open(pipex->output_file, \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->fd_out < 0)
			perror("Error, cannot open file");
	}
}
