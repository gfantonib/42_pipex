/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:40:50 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/04 13:26:47 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
}

void	get_fd_input(t_pipex *pipex)
{
	if (access(pipex->input_file, F_OK) != 0)
		error_message_file(pipex, 1);
	else if (access(pipex->input_file, R_OK) != 0)
		error_message_file(pipex, 2);
	pipex->fd_in = open(pipex->input_file, O_RDONLY);
	if (pipex->fd_in < 0)
		error_message_file(pipex, 3);
}

void	get_fd_output(t_pipex *pipex)
{
	pipex->fd_out = open(pipex->output_file, \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out < 0)
		error_message_file(pipex, 3);
}
