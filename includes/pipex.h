/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:35:18 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/02 11:48:01 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_cmd
{
	char	**cmd;
	char	*cmd_path;
	int		pid;
	char	cmd_position;
}		t_cmd;

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
	int		nbr_of_cmds;
	int		cmd_index;
	char	*input_file;
	char	*output_file;
	t_cmd	*cmds_str;
}		t_pipex;

void	get_cmds(t_pipex *pipex, char **argv, char **envp);
char	*get_path(char *cmd, char **envp);

void	error_message(int flag);
void	error_message_free(t_pipex *pipex, int flag);
void	error_message_file(int flag);
void	close_all(t_pipex *pipex);

void	get_fd_file(t_pipex *pipex, char **argv);
void	get_file_name(t_pipex *pipex, char **argv);
void	get_fd_input(t_pipex *pipex);
void	get_fd_output(t_pipex *pipex);

void	exec_cmds(t_pipex *pipex);
void	exec_child(t_pipex *pipex, int i);
void	exec_initial(t_pipex *pipex, int i);
void	exec_mediate(t_pipex *pipex, int i);
void	exec_final(t_pipex *pipex, int i);

void	free_all(t_pipex *pipex, int i);
void	free_cmd_array(t_cmd cmds_str);
void	free_split(char **split);
void	set_to_null(t_pipex *pipex);

#endif
