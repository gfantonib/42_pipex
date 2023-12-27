#include "../includes/bonus_pipex.h"

void	get_cmds(t_pipex *pipex, char **argv, char **envp)
{
	int	i;
	int	cmd_index;

	envp = NULL;

	pipex->cmds_array = (t_cmd *)malloc(sizeof(t_cmd) * pipex->nbr_of_cmds);
	if (!pipex->cmds_array)
		error_message(2);

	i = 0;
	cmd_index = pipex->cmd_index;
	while (i < pipex->nbr_of_cmds)
	{
		pipex->cmds_array[i].cmd = ft_split(argv[cmd_index], ' ');
		cmd_index++;
		i++;
	}
}

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
			printf("%s ", pipex->cmds_array[i].cmd[j]);
			j++;
		}
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