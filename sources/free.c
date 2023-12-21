#include "../includes/pipex.h"

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