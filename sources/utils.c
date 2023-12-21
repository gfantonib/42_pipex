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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_all(t_pipex *pipex)
{
	if (pipex->path_cmd1)
		free(pipex->path_cmd1);
	if (pipex->path_cmd2)
		free(pipex->path_cmd2);

	free_split(pipex->cmd1);
	free_split(pipex->cmd2);

	free(pipex->infile_str);
	free(pipex->outfile_str);

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
