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
}		t_pipex;

void	error_message(int flag);
