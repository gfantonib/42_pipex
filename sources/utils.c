#include "../includes/pipex.h"

void	error_message(int flag)
{
	if (flag == 1)
		puts("argc error");
	else if (flag == 2)
		puts("fork error");
	else if (flag == 3)
		puts("execve error");
	else if (flag == 4)
		puts("pipe creation error");
	else if (flag == 5)
		puts("open error");
	else if (flag == 6)
		puts("command error");
	exit(EXIT_FAILURE);
}

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while(cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
	error_message(6);
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