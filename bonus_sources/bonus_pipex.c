#include "../includes/bonus_pipex.h"

void	initial_values(t_pipex *pipex, int argc)
{
	pipex->nbr_of_cmds = argc - 3;
	pipex->cmd_index = 2;
}

// void	tester(t_pipex *pipex)
// {
// 	int i;
// 	int	j;

// 	i = 0;
// 	while (i < pipex->nbr_of_cmds)
// 	{
// 		j = 0;
// 		printf("cmd: ");
// 		while (pipex->cmds_array[i].cmd[j])
// 		{
// 			printf("%s ", pipex->cmds_array[i].cmd[j]);
// 			j++;
// 		}
// 		printf("\n");
// 		printf("path: %s\n", pipex->cmds_array[i].cmd_path);
// 		printf("\n");
// 		i++;
// 	}
// 	printf("%s\n", pipex->input_file);
// 	printf("%s\n", pipex->output_file);
// }

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		error_message(1);
	initial_values(&pipex, argc);
	get_fd_file(&pipex, argv);
	get_cmds(&pipex, argv, envp);
	exec_cmds(&pipex);

	//tester(&pipex);
	return (0);
}