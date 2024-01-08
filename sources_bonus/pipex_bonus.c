/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:40:33 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/08 13:34:31 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	initial_values(t_pipex *pipex, int argc)
{
	pipex->nbr_of_cmds = argc - 3;
	pipex->cmd_index = 2;
	pipex->exit_status = 1;
	pipex->has_heredoc = 'F';
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	initial_values(&pipex, argc);
	if (argc < 5)
		error_message_exit(&pipex, 1);
	else if (!ft_strncmp(argv[1], "here_doc", 8) && (argc < 6))
		error_message_exit(&pipex, 2);
	get_fd_file(&pipex, argv);
	get_cmds(&pipex, argv, envp);
	exec_cmds(&pipex);
	return (0);
}
