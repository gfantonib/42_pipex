#include "../includes/bonus_pipex.h"

void	free_all(t_pipex *pipex, int i)
{
	while (i < pipex->nbr_of_cmds)
	{
		free_cmd_array(pipex->cmds_array[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	free_cmd_array(t_cmd cmd_array)
{
	free(cmd_array.cmd_path);
	free_split(cmd_array.cmd);
	//free(&cmd_array);
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