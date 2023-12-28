#include "../includes/bonus_pipex.h"

// void	get_commands(t_pipex *pipex, char **argv)
// {
// 	pipex->cmd1 = ft_split(argv[2], ' ');
// 	pipex->cmd2 = ft_split(argv[3], ' ');
// 	pipex->infile_str = ft_strdup(argv[1]);
// 	pipex->outfile_str = ft_strdup(argv[4]);
// }

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

void	get_cmds(t_pipex *pipex, char **argv, char **envp)
{
	int	i;
	int	cmd_index;

	pipex->cmds_array = (t_cmd *)malloc(sizeof(t_cmd) * pipex->nbr_of_cmds);
	if (!pipex->cmds_array)
		error_message(2);

	i = 0;
	cmd_index = pipex->cmd_index;
	while (i < pipex->nbr_of_cmds)
	{
		pipex->cmds_array[i].cmd = ft_split(argv[cmd_index], ' ');
		pipex->cmds_array[i].cmd_path = get_path(pipex->cmds_array[i].cmd[0], envp);
		pipex->cmds_array[i].pid = -1;
		if (i == 0)
			pipex->cmds_array[i].cmd_position = 'I';
		else if (i < (pipex->nbr_of_cmds - 1))
			pipex->cmds_array[i].cmd_position = 'M';
		else
			pipex->cmds_array[i].cmd_position = 'F';

		cmd_index++;
		i++;
	}
}

// void	get_commands_path(t_pipex *pipex, char **envp)
// {
// 	pipex->path_cmd1 = get_path(pipex->cmd1[0], envp);
// 	pipex->path_cmd2 = get_path(pipex->cmd2[0], envp);
// 	if (!pipex->path_cmd1 || !pipex->path_cmd2)
// 		error_message_free(pipex, 2);
// }
