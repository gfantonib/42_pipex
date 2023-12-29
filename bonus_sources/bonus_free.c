#include "../includes/bonus_pipex.h"

void	free_all(t_pipex *pipex, int i)
{
	while (i < pipex->nbr_of_cmds)
	{
		free_cmd_array(pipex->cmds_array[i]);
		i++;
	}
	free(pipex->cmds_array);
	exit(EXIT_FAILURE);
}

void	free_cmd_array(t_cmd cmd_array)
{
	if (cmd_array.cmd_path)
		free(cmd_array.cmd_path);
	if (cmd_array.cmd)
		free_split(cmd_array.cmd);
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

void	set_to_null(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->nbr_of_cmds)
	{
		pipex->cmds_array[i].cmd = NULL;
		pipex->cmds_array[i].cmd_path = NULL;
		i++;
	}
}