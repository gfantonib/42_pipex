#include "../includes/pipex.h"

void	get_commands(t_pipex *pipex, char **argv)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->infile_str = ft_strdup(argv[1]);
	pipex->outfile_str = ft_strdup(argv[4]);
}

void	get_commands_path(t_pipex *pipex, char **envp)
{
	pipex->path_cmd1 = get_path(pipex->cmd1[0], envp);
	pipex->path_cmd2 = get_path(pipex->cmd2[0], envp);
	if (!pipex->path_cmd1 || !pipex->path_cmd2)
		error_message(pipex, 2);
}

// void	wait_child(t_pipex *pipex)
// {
// 	int	status;
	
// 	pipex->error_flag = 0;
// 	waitpid(pipex->pid1, &status, 0);
// 	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
// 		exit(EXIT_FAILURE);
// 	waitpid(pipex->pid2, &status, 0);
// 	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
// 		exit(EXIT_FAILURE);
// }

void	fill_pipex(t_pipex *pipex, char **argv, char **envp)
{
	get_commands(pipex, argv);
	get_commands_path(pipex, envp);
}

void	execute_commands(char **argv, char **envp)
{
	t_pipex	pipex;
	int	status;

	int	fd[2];

	if (pipe(fd) == -1)
	{
		ft_putstr_fd("pipe creation error\n", 2);
		exit(EXIT_FAILURE);
	}
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
	{
		ft_putstr_fd("fork error\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (pipex.pid1 == 0)
	{
		fill_pipex(&pipex, argv, envp);
		child_process_1(&pipex, fd);
	}

	waitpid(pipex.pid1, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		exit(EXIT_FAILURE);

	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
	{
		ft_putstr_fd("fork error\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (pipex.pid2 == 0)
	{
		fill_pipex(&pipex, argv, envp);
		child_process_2(&pipex, fd);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pipex.pid2, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		exit(EXIT_FAILURE);
}