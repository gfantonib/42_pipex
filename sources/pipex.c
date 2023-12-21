#include "../includes/pipex.h"

void	success_or_error(int error_flag)
{
	if (error_flag == 1)
		exit(EXIT_FAILURE);
	else if (error_flag == 0)
		puts("success!");
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		error_message(&pipex, 1);
	get_commands(&pipex, argv);
	get_commands_path(&pipex, envp);
	execute_commands(&pipex);
	free_all(&pipex);
	success_or_error(pipex.error_flag);
	return (0);
}