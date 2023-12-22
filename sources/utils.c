#include "../includes/pipex.h"

void	error_message(t_pipex *pipex, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("argc error\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (flag == 2)
		ft_putstr_fd("command error\n", 2);
	else if (flag == 3)
		ft_putstr_fd("pipe creation error\n", 2);
	else if (flag == 4)
		ft_putstr_fd("fork error\n", 2);
	else if (flag == 5)
		ft_putstr_fd("open error\n", 2);
	else if (flag == 6)
		ft_putstr_fd("execve error\n", 2);
	else if (flag == 7)
		ft_putstr_fd("execve/waitpid error\n", 2);
	else if (flag == 8)
		ft_putstr_fd("success\n", 2);
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
