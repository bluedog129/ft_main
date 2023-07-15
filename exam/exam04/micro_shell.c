#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	print_error(char *msg)
{
	int	len;

	len = 0;
	while (msg[len])
		len++;
	write(STDERR_FILENO, msg, len);
}

void	if_error_then_exit(int ret)
{
	if (ret == -1)
	{
		print_error("error: fatal\n");
		exit(0);
	}
}

int	find_stop_idx(char **argv)
{
	int	idx;

	idx = 0;
	while (argv[idx])
	{
		if (strcmp(argv[idx], ";") == 0)
			break ;
		else if (strcmp(argv[idx], "|") == 0)
			break ;
		idx++;
	}
	return (idx);
}

void	execve_with_error(char **cmd, char **env)
{
	if (execve(cmd[0], cmd, env) == -1)
	{
		print_error("error: cannot execute ");
		print_error(cmd[0]);
		write(STDERR_FILENO, "\n", 1);
	}
	exit(1);
}

void	execute(char **cmd, char **env, int *wait_cnt)
{
	pid_t	pid;

	if (cmd[0] == NULL)
		return ;

	if (strcmp(cmd[0], "cd") == 0)
	{
		if (cmd[2] != NULL)
			print_error("error: cd: bad argument\n");
		else if (chdir(cmd[1]) == -1)
		{
			print_error("error: cannot change directory to ");
			print_error(cmd[1]);
			print_error("\n");
		}
	}
	else
	{
		if_error_then_exit(pid = fork());
		if (pid == 0)
			execve_with_error(cmd, env);
		*wait_cnt = 1;
	}
}

void	pipex(char **argv, char **env, int exec_idx, int *stop_idx, int *wait_cnt)
{
	int	pid;
	int	old_fd[2] = {0, }, new_fd[2];

	while (1)
	{
		if_error_then_exit(pipe(new_fd));
		if_error_then_exit(pid = fork());
		if (pid == 0)
		{
			close(new_fd[0]);
			dup2(new_fd[1], STDOUT_FILENO);
			if (old_fd[1] != 0)
				close(old_fd[1]);
			dup2(old_fd[0], STDIN_FILENO);
			argv[*stop_idx] = NULL;
			execve_with_error(&argv[exec_idx], env);
		}
		close(new_fd[1]);
		if (old_fd[0] != 0)
			close(old_fd[0]);
		old_fd[0] = new_fd[0], old_fd[1] = new_fd[1];
		(*wait_cnt)++;
		exec_idx = ++(*stop_idx);
		*stop_idx += find_stop_idx(&argv[*stop_idx]);
		if (argv[*stop_idx] == NULL || strcmp(argv[*stop_idx], ";") == 0)
			break ;
	}
	if_error_then_exit(pid = fork());
	if (pid == 0)
	{
		close(old_fd[1]);
		dup2(old_fd[0], STDIN_FILENO);
		argv[*stop_idx] = NULL;
		execve_with_error(&argv[exec_idx], env);
	}
	close(new_fd[1]);
	close(old_fd[0]);
	(*wait_cnt)++;
}

int	main(int argc, char *argv[], char *env[])
{
	int	wait_cnt;
	int	exec_idx;
	int	stop_idx;

	exec_idx = 1;
	while (exec_idx < argc)
	{
		wait_cnt = 0;
		stop_idx = exec_idx + find_stop_idx(&argv[exec_idx]);
		// 마지막이거나 ';'를 만났다면
		if (argv[stop_idx] == NULL || strcmp(argv[stop_idx], ";") == 0)
		{
			argv[stop_idx] = NULL;
			execute(&argv[exec_idx], env, &wait_cnt);
		}
		// '|'를 만났다면
		else
			pipex(argv, env, exec_idx, &stop_idx, &wait_cnt);
		// 위에서 실행시킨 명령어가 끝날 때까지 기다린다.
		while (wait_cnt--)
			waitpid(-1, NULL, 0);
		exec_idx = stop_idx + 1;
	}
	return (0);
}