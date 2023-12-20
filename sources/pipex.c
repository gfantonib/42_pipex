#include "../includes/pipex.h"

void	success_or_error(int error_flag)
{
	if (error_flag == 1)
		exit(EXIT_FAILURE);
	else
		puts("success!");
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int	status;

	pipex.error_flag = 1;
	if (argc != 5)
		error_message(&pipex, 1);
	get_commands(&pipex, argv);
	get_commands_path(&pipex, envp);
	execute_commands(&pipex);

	waitpid(pipex.pid1, &status, 0);
	//if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		//pipex.error_flag = 1;
	waitpid(pipex.pid2, &status, 0);
	//if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		//pipex.error_flag = 1;
	free_all(&pipex);
	success_or_error(pipex.error_flag);
	return (0);
}