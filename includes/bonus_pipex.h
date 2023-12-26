#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef	struct s_pipex
{
	char	*path_cmd1;
	char	**cmd1;

	char	*path_cmd2;
	char	**cmd2;

	char	*infile_str;
	char	*outfile_str;

	int		fdin;
	int		fdout;

	int		error_flag;

}		t_pipex;

void	call_to_children(char **argv, char **envp);
void	get_commands(t_pipex *pipex, char **argv);
void	get_commands_path(t_pipex *pipex, char **envp);
char	*get_path(char *cmd, char **envp);
void	child_process_1(char **argv, char **envp, int *fd);
void	child_process_2(char **argv, char **envp, int *fd);
void	error_message(int flag);
void	error_message_free(t_pipex *pipex, int flag);
void	free_all(t_pipex *pipex);
void	free_split(char **split);



