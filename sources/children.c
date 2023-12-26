#include "../includes/pipex.h"

void	child_process_1(char **argv, char **envp, int *fd)
{
		t_pipex pipex;

		get_commands(&pipex, argv);
		get_commands_path(&pipex, envp);
		pipex.fdin = open(pipex.infile_str, O_RDONLY, 0777);
		if (pipex.fdin == -1)
			error_message_free(&pipex, 5);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipex.fdin, STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (execve(pipex.path_cmd1, pipex.cmd1, NULL) == -1)
			error_message_free(&pipex, 6);
}

void	child_process_2(char **argv, char **envp, int *fd)
{
		t_pipex pipex;

		get_commands(&pipex, argv);
		get_commands_path(&pipex, envp);
		pipex.fdout = open(pipex.outfile_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex.fdout == -1)
			error_message_free(&pipex, 5);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipex.fdout, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (execve(pipex.path_cmd2, pipex.cmd2, NULL) == -1)
			error_message_free(&pipex, 6);
}

void	call_to_children(char **argv, char **envp)
{
	int pid;
	int	status;
	int	fd[2];

	if (pipe(fd) == -1)
		error_message(3);
	pid = fork();
	if (pid < 0)
		error_message(4);
	else if (pid == 0)
		child_process_1(argv, envp, fd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		error_message(7);
	pid = fork();
	if (pid < 0)
		error_message(4);
	else if (pid == 0)
		child_process_2(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
	error_message(7);
}