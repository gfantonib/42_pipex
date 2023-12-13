#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	int	id;

	char *str = malloc(4);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';

	id = fork();
	if (id == 0)
	{
		printf("------------------------child ------------------------\n");
		printf("str = %s | add = %p\n", str, &str[0]);
		str[0] = '1';
		printf("after modification str = %s | add = %p\n", str, &str[0]);
		printf("%d\n", id);
		printf("str[0]:%c\n", str[0]);
		exit(1);
	}
	else
	{	
		wait(NULL);
		printf("------------------------parent ------------------------\n");
		printf("str = %s | add = %p\n", str, &str[0]);
		printf("%d\n", id);
		printf("str[0]:%c\n", str[0]);
	}
	return (0);
}