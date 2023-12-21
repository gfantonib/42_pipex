#include "../includes/pipex.h"

void	child_process_1(t_pipex *pipex, int *fd)
{
		int		fdin;

		fdin = open(pipex->infile_str, O_RDONLY, 0777);
		if (fdin == -1)
			error_message(pipex, 5);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fdin, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (execve(pipex->path_cmd1, pipex->cmd1, NULL) == -1)
			error_message(pipex, 6);
}

void	child_process_2(t_pipex *pipex, int *fd)
{
		int		fdout;

		fdout = open(pipex->outfile_str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fdout == -1)
			error_message(pipex, 5);
		dup2(fd[0], STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (execve(pipex->path_cmd2, pipex->cmd2, NULL) == -1)
			error_message(pipex, 6);
}