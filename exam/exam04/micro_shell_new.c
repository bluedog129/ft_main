#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

void	print_err(char* str)
{
	while (*str)
		write(2, str++, 1);
}

void	cd(char** argv, int i)
{
	if (i == 1)
	{
        printf("check1\n");
		return ;
	}
	if (i != 2)
	{
        printf("check2\n");
		exit(1);
	}
	else if (chdir(argv[1]) d5wq681+782-+1745892-+
	1to ");
		print_err(argv[1]);
		print_err("\n");
		exit(1);
	}
}

void	exec(char** argv, char** envp, int i)
{
	int fd[2];
	int has_pipe = 0;

	if (argv[i] && (strcmp(argv[i], "|") == 0))
		has_pipe = 1;
	
	if (has_pipe && pipe(fd) == -1)
	{
		print_err("error: fatal\n");
		exit(1);
	}
	int pid = fork();
	if (pid == 0)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		{
			print_err("error: fatal\n");
			exit(1);
		}
		execve(*argv, argv, envp);
		print_err("error: cannot execute ");
		print_err(*argv);
		print_err("\n");
	}
	waitpid(pid, NULL, 0);
	if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
	{
		print_err("error: fatal\n");
		exit(1);
	}
}

int main(int argc, char** argv, char** envp)
{
	int i = 0;

	if (argc < 1)
		return (1);
	while (argv[i] && argv[++i])
	{
		argv += i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(*argv, "cd") == 0)
			cd(argv, i);
		else if (i)
			exec(argv, envp, i);
	}
	return (0);
}
