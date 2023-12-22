#include "../includes/pipex.h"

void	success_or_error(t_pipex *pipex, int error_flag)
{
	if (error_flag == 1)
		error_message(pipex, 7);
	else if (error_flag == 0)
		error_message(pipex, 8);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		error_message(&pipex, 1);
	//get_commands(&pipex, argv);
	//get_commands_path(&pipex, envp);
	execute_commands(argv, envp);
	ft_putstr_fd("success", 2);
	return (0);
}