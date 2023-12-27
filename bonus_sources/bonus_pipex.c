#include "../includes/bonus_pipex.h"

void	initial_values(t_pipex *pipex, int argc)
{
	pipex->nbr_of_cmds = argc - 3;
	pipex->cmd_index = 2;
}

void	tester(t_pipex *pipex)
{
	int i;
	int	j;

	i = 0;
	while (i < pipex->nbr_of_cmds)
	{
		j = 0;
		while (pipex->cmds_array[i].cmd[j])
		{
			printf("cmd: %s\n", pipex->cmds_array[i].cmd[j]);
			j++;
		}
		printf("path: %s\n", pipex->cmds_array[i].cmd_path);
		printf("\n");
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		error_message(1);
	initial_values(&pipex, argc);
	get_cmds(&pipex, argv, envp);
	tester(&pipex);
	return (0);
}