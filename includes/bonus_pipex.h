#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_cmd
{
	char 	**cmd;
	char 	*cmd_path;
	char	**argv;
	char	**envp;

}		t_cmd;

typedef	struct s_pipex
{
	int	fd_in;
	int	fd_out;

	int	nbr_of_cmds;
	int	cmd_index;

	char *input_file;
	char *output_file;

	t_cmd	*cmds_array;

}		t_pipex;

void	get_cmds(t_pipex *pipex, char **argv, char **envp);
char	*get_path(char *cmd, char **envp);
void	error_message(int flag);
void	free_split(char **split);
void	get_fd_file(t_pipex *pipex, char **argv);
void	get_file_name(t_pipex *pipex, char **argv);
void	get_fd_input(t_pipex *pipex);
void	get_fd_output(t_pipex *pipex);



