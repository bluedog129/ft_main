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
		print_err("error: cd: bad arguments\n");
		return ;
	}
	if (i != 2)
	{
        printf("check2\n");
		print_err("error: cd: bad arguments\n");
		exit(1);
	}
	else if (chdir(argv[1]) == -1)
	{
		print_err("error: cd: cannot change directory to ");
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
        printf("i : %d\n", i);
        printf("argv : %s\n", *argv);
		if (strcmp(*argv, "cd") == 0)
			cd(argv, i);
		else if (i)
			exec(argv, envp, i);
	}
	return (0);
}
