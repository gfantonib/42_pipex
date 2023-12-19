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
	else if (flag == 7)
		puts("file_name error");
	else if (flag == 8)
		puts("success!");
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
	free_split(pipex->cmd1);
	free_split(pipex->cmd2);

	free(pipex->infile);
	free(pipex->outfile);

	free(pipex->path_cmd1);
	free(pipex->path_cmd2);
	
	error_message(8);
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
	free(paths);
	return (0);
}