#include <errno.h>
#include<string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	int array[2];
	char str1[100];
	char str2[100];
	if (pipe(array) == -1)
	{
	 	perror("Filed to create pipe");
	   	exit(1);
	}
	scanf("%s", str1);
	write(array[1], str1, strlen(str1)+1);
	printf("\n");
	read(array[0], str2, 100);
	printf("%s", str2);
	printf("\n");
}