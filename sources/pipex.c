#include "../includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		error_message(1);
	get_commands(&pipex, argv);
	get_commands_path(&pipex, envp);
	execute_commands(&pipex);

	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);

	free_all(&pipex);
	return (0);
}