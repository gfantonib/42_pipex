#include "../includes/pipex.h"

void	initial_values(t_pipex *pipex, int argc)
{
	pipex->nbr_of_cmds = argc - 3;
	pipex->cmd_index = 2;
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		error_message(1);
	initial_values(&pipex, argc);
	get_fd_file(&pipex, argv);
	get_cmds(&pipex, argv, envp);
	exec_cmds(&pipex);
	return (0);
}