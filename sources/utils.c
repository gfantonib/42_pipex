#include "../includes/pipex.h"

void	error_message(int flag)
{
	if (flag == 1)
	{
		puts("argc error");
		exit(1);
	}
	if (flag == 2)
	{
		puts("fork error");
		exit(2);
	}
	if (flag == 3)
	{
		puts("execv error");
		exit(2);
	}
}