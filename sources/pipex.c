#include "../includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error_message(1);
	call_to_children(argv, envp);
	error_message(8);
	return (0);
}