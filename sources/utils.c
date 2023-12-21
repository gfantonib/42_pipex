#include "../includes/pipex.h"

void	error_message(t_pipex *pipex, int flag)
{
	if (flag == 1)
	{
		puts("argc error");
		exit(EXIT_FAILURE);
	}
	else if (flag == 2)
		puts("command error");
	else if (flag == 3)
		puts("pipe creation error");
	else if (flag == 4)
		puts("fork error");
	else if (flag == 5)
		puts("open error");
	else if (flag == 6)
		puts("execve error");
	free_all(pipex);
	exit(EXIT_FAILURE);
}

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
		{
			free_split(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_split(paths);
	return (0);
}

void	wait_child(t_pipex *pipex)
{
	int	status;
	
	pipex->error_flag = 0;
	waitpid(pipex->pid1, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		pipex->error_flag = 1;
	waitpid(pipex->pid2, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		pipex->error_flag = 1;
}
