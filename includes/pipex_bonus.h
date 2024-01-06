/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:08:36 by gfantoni          #+#    #+#             */
/*   Updated: 2024/01/06 12:30:12 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"

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
	int		exit_status;
	char	*input_file;
	char	*output_file;
	char	has_heredoc;
	char	*limiter;
	t_cmd	*cmds_str;
}		t_pipex;

void	get_cmds(t_pipex *pipex, char **argv, char **envp);
char	*get_path(char *cmd, char **envp);

void	error_message(t_pipex *pipex, int i, int flag);
void	error_message_exit(t_pipex *pipex, int flag);
void	error_message_free(t_pipex *pipex, int flag);
void	error_message_file(t_pipex *pipex, int flag);
void	get_exit_status(t_pipex *pipex);

void	close_all(t_pipex *pipex);
void	close_pipe_and_fdin(t_pipex *pipex);

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

void	here_doc(t_pipex *pipex);

#endif