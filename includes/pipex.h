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

	char	*infile;
	char	*outfile;

	int		pid1;
	int		pid2;

	int		error_flag;

}		t_pipex;

void	error_message(int flag);
void	get_commands(t_pipex *pipex, char **argv);
void	get_commands_path(t_pipex *pipex, char **envp);
void	free_split(char **split);
char	*get_path(char *cmd, char **envp);
void	execute_commands(t_pipex *pipex);
void	child_process_1(t_pipex *pipex, int *fd);
void	child_process_2(t_pipex *pipex, int *fd);
void	free_all(t_pipex *pipex);



