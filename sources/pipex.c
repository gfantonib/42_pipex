#include "../includes/pipex.h"

void	child_process_1(t_pipex *pipex, int *fd)
{

		int		fdin;

		fdin = open(pipex->infile, O_RDONLY, 0777);

		dup2(fd[1], STDOUT_FILENO);
		dup2(fdin, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);

		if (execve(pipex->path_cmd1, pipex->cmd1, NULL) == -1)
		error_message(3);
}

void	child_process_2(t_pipex *pipex, int *fd)
{
		int		fdout;

		fdout = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);

		dup2(fd[0], STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);

		if (execve(pipex->path_cmd2, pipex->cmd2, NULL) == -1)
		error_message(3);
}

// int execve(const char *pathname, char *const argv[], char *const envp[]);

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	get_cmd_and_path(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->path_cmd1 = get_path(pipex->cmd1[0], envp);
	pipex->path_cmd2 = get_path(pipex->cmd2[0], envp);
	pipex->infile = ft_strdup(argv[1]);
	pipex->outfile = ft_strdup(argv[4]);
}

int main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error_message(1);

	t_pipex	pipex;
	get_cmd_and_path(&pipex, argv, envp);

	int	fd[2];
	if (pipe(fd) == -1)
		return (1);
	
	int pid1 = fork();
	if (pid1 < 0)
		error_message(2);

	if (pid1 == 0) // Child process 1 (ping)
		child_process_1(&pipex, fd);

	int	pid2 = fork();
	if (pid2 < 0)
		error_message(2);

	if (pid2 == 0) // Child process 2 (grep)
		child_process_2(&pipex, fd);

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}