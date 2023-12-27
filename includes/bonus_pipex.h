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
	char	**argv;
	char	**envp;

}		t_cmd;

typedef	struct s_pipex
{
	int	fd_in;
	int	fd_out;

	int	nbr_of_cmds;
	int	cmd_index;

	t_cmd	*cmds_array;

}		t_pipex;

void	error_message(int flag);



