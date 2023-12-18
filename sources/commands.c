#include "../includes/pipex.h"

void	get_commands(t_pipex *pipex, char **argv)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->infile = ft_strdup(argv[1]);
	pipex->outfile = ft_strdup(argv[4]);
}

void	get_commands_path(t_pipex *pipex, char **envp)
{
	pipex->path_cmd1 = get_path(pipex->cmd1[0], envp);
	pipex->path_cmd2 = get_path(pipex->cmd2[0], envp);

}

void	execute_commands(t_pipex *pipex)
{
	int	fd[2];

	if (pipe(fd) == -1)
		error_message(4);
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		error_message(2);
	if (pipex->pid1 == 0) // Child process 1
		child_process_1(pipex, fd);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error_message(2);
	if (pipex->pid2 == 0) // Child process 2
		child_process_2(pipex, fd);
	close(fd[0]);
	close(fd[1]);
}