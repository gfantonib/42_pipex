#include "../includes/pipex.h"

void	close_all(t_pipex *pipex)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(pipex->fd_in);
	close(pipex->fd_out);
}

void close_pipe_and_fdin(t_pipex *pipex)
{
	close(pipex->fd_pipe[0]);
	close(pipex->fd_pipe[1]);
	close(pipex->fd_in);
}