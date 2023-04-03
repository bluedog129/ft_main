# pipex : Replicates the functionality of the shell command pipeline!

<details>
<summary>External functions</summary>
<div markdown="1">

open, close, read, write, malloc, free, perror, strerror, access, 
dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid    

- open () : The open() function is used in C programming language to open a file and get a file descriptor that can be used for reading, writing or both. The function takes two main arguments: the file name and a set of flags to specify the mode in which the file should be opened. Here are some of the commonly used options for the open() function:  

	O_RDONLY: Opens the file in read-only mode.  
	O_WRONLY: Opens the file in write-only mode.  
	O_RDWR: Opens the file in read/write mode.  
	O_CREAT: Creates the file if it does not exist.  
	O_TRUNC: Truncates the file to zero length if it already exists.  
	O_APPEND: Appends data to the end of the file.  
	O_EXCL: Creates the file exclusively, meaning that if the file already exists, the open operation fails.  

```c
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("myfile.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    // Do something with the file...
    close(fd);
    return 0;
}
```

- perror(): This function is used to print an error message to the console.  
```c
perror("Error message");
```

- strerror(): This function is used to get a string describing the error code passed as an argument.  
```c
char *errorString = strerror(errno);
printf("Error message: %s\n", errorString);
```

- access(): This function is used to check if a file or directory can be accessed.  
```c
int result = access("file.txt", R_OK);
if (result == -1) {
   perror("Error accessing file");
   exit(EXIT_FAILURE);
}
```

- dup(): This function is used to duplicate a file descriptor.  
```c
int fd2 = dup(fd);
if (fd2 == -1) {
   perror("Error duplicating file descriptor");
   exit(EXIT_FAILURE);
}
```

- dup2(): This function is used to duplicate a file descriptor to a specified file descriptor.  
```c
int fd2 = dup2(fd, STDOUT_FILENO);
if (fd2 == -1) {
   perror("Error duplicating file descriptor");
   exit(EXIT_FAILURE);
}
```

- execve(): This function is used to replace the current process with a new process.  
```c
char *args[] = {"ls", "-l", NULL};
execve("/bin/ls", args, NULL);
perror("Error executing program");
exit(EXIT_FAILURE);
```

- fork(): This function is used to create a new process.  
```c
pid_t childPid = fork();
if (childPid == -1) {
   perror("Error forking process");
   exit(EXIT_FAILURE);
}
if (childPid == 0) {
   // Child process
} else {
   // Parent process
}
```

- pipe(): This function is used to create a pipe for interprocess communication.  
```c
int pipefd[2];
int result = pipe(pipefd);
if (result == -1) {
   perror("Error creating pipe");
   exit(EXIT_FAILURE);
}
```

- unlink(): This function is used to delete a file.   
```c
int result = unlink("file.txt");
if (result == -1) {
   perror("Error deleting file");
   exit(EXIT_FAILURE);
}
```

- wait(): This function is used to wait for a child process to terminate.   
```c
pid_t childPid = fork();
if (childPid == -1) {
   perror("Error forking process");
   exit(EXIT_FAILURE);
}
if (childPid == 0) {
   // Child process
   exit(EXIT_SUCCESS);
} else {
   // Parent process
   int status;
   pid_t result = wait(&status);
   if (result == -1) {
      perror("Error waiting for child process");
      exit(EXIT_FAILURE);
   }
   if (WIFEXITED(status)) {
      printf("Child process exited with status %d\n", WEXITSTATUS(status));
   }
}
```

- waitpid(): This function is used to wait for a specific child process to terminate.   
```c
pid_t childPid = fork();
if (childPid == -1) {
   perror("Error forking process");
   exit(EXIT_FAILURE);
}
if (childPid == 0) {
   // Child process
   exit(EXIT_SUCCESS);
} else {
   // Parent process
   int status;
   pid_t result = waitpid(childPid, &status, 0);
   if (result == -1) {
      perror("Error waiting for child process");
      exit(EXIT_FAILURE);
   }
   if (WIFEXITED(status)) {
      printf("Child process exited with status %d\n", WEXITSTATUS(status));
   }
}
```

</div>
</details>

## What is a Process?
A process is an executing program with a unique process identifier (PID) assigned by the operating system when it is started. Each process has its own virtual memory space, including its allocated memory, stack and heap.  

## What are IPC Mechanisms?

Interprocess communication (IPC) mechanisms allow processes to communicate and share data with each other. Some common IPC mechanisms are pipes, message queues and shared memory. Pipes are a simple form of IPC that allow unidirectional data flows between two processes, where one process writes data to the pipe and the other reads from the pipe.  

Processes can communicate with each other using IPC mechanisms such as pipes, message queues and shared memory. Pipes are a simple form of IPC that allow two processes to communicate via a unidirectional stream of data. One process writes data to the pipe and the other reads data from the pipe.   

- Pipes: Unidirectional communication channels for transferring data between processes.    

- Named pipes (FIFOs): Similar to pipes, but can be used between unrelated processes, identified by a name in the file system.  

- Message queues: A method of exchanging messages between processes, managed by the operating system. Message queues facilitate the transmission of messages containing data to designated receivers.  

- Shared memory: A region of memory that is accessible to multiple processes, allowing them to exchange data. Shared memory is an efficient alternative to pipes or message queues for exchanging data between processes.  

- Semaphores: Synchronisation primitives that help coordinate activities between processes and protect shared resources from concurrent access by multiple processes.  

- Sockets: Communication endpoints that allow data to be exchanged between processes over a network or within the same machine. Sockets are useful for implementing client-server and other network-based applications.  

IPC mechanisms are essential for building complex systems involving multiple processes or threads. They allow processes to communicate and synchronise their activities, facilitating the development of efficient, reliable and scalable systems.  

## How does a Pipe Work?  

A pipe is an IPC mechanism that allows unidirectional data transfer between two processes. One process writes data to the pipe, while the other reads data from the pipe. In Unix-like systems, the pipe system call creates a pipe, and the read and write system calls handle the data transfer through the pipe.   

Typically, a process creates a pipe using the fork system call, which spawns a new process. After the fork, the process uses the pipe() system call to create a new pipe and is given a pair of file descriptors. One file descriptor handles writing to the pipe, while the other handles reading from the pipe.  

The parent process writes to the pipe using the write file descriptor and the child process reads from the pipe using the read file descriptor. This setup allows bi-directional communication between the two processes using the pipe.   

Pipes are commonly used in shell scripting and other Unix-based systems to link two or more commands. This allows the output of one command to serve as the input for another, a technique known as pipeline processing, which allows complex data processing pipelines to be created with minimal effort.  

## My code
### Header
```c
enum e_pipex_enum
{
	SUCCESS = 1,
	EQUAL = 0,
	FINISH = 1,
	MIN_ARGS = 4
};

typedef struct arg
{
	char	**commands;
	char	**paths;
	char	**current_command;
	char	*infile_str;
	char	*outfile_str;
	char	*full_path;
	char	*limiter;
	int		input_fd;
	int		output_fd;
	int		prev_fd;
	int		tmp_fd;
	int		command_count;
	int		argc;
	int		here_doc;
}	t_arg;
```
type arg is a structure for storing commands, bin paths, etc.  
The pid is used to store the process IDs of the child processes created by the fork() system call when the commands are executed in a pipeline.

```c
int	main(int argc, char **argv, char **envp)
{
	t_arg	*arg;

	if (validate_args(argc) == ERROR)
		return (EXIT_FAILURE);
	arg = malloc(sizeof(t_arg));
	initialize_structs(argc, argv, envp, arg);
	apply_heredoc(arg);
	apply_pipe(arg);
	free_arg(arg);
	return (EXIT_SUCCESS);
}
```
The main flow of my PipeX is as follows.  
1. validate the incoming string arguments (path, command)   
2. initialize the structure  
3. apply here_doc (if the here_doc switch is on)
4. apply the pipe

## main flow functions
### validate_args()
```c
static int	validate_args(int argc)
{
	if (argc < MIN_ARGS)
	{
		perror("ERROR : argument error\n");
		return (ERROR);
	}
	return (SUCCESS);
}
```
The string validation function is simple.  
It takes an executable, two commands, an infile, an outfile, and an optional here_doc, and handles the condition that the argument must consist of an executable.

### initialize_structs()
```c
static void	initialize_structs(int argc, char **argv, char **envp, t_arg *arg)
{
	if (strcmp(argv[1], "here_doc") == 0)
	{
		arg->here_doc = 1;
		arg->infile_str = argv[2];
		arg->limiter = ft_strjoin(argv[2], "\n");
	}
	else
	{
		arg->here_doc = 0;
		arg->infile_str = argv[1];
	}
	arg->commands = get_commands(arg, argv);
	arg->paths = get_paths(envp);
	arg->argc = argc;
	arg->outfile_str = argv[argc - 1];
}
```
Optionally initialize the required resources to the structure

### apply_heredoc()
```c
void	apply_heredoc(t_arg *arg)
{
	if (arg->here_doc == 0)
		return ;
	if (open_tmp_file(arg) == ERROR)
	{
		perror("ERROR: Failed to open file\n");
		return ;
	}
	while (1)
	{
		if (get_heredoc_line(arg) == FINISH)
			break ;
	}
	arg->tmp_fd = open("temp.txt", O_RDONLY);
}
```
First open tmp_file  
Second, put the string coming in via here_doc in tmp_file.

### apply_pipe
```c
static void	create_pipe(int *fd)
{
	if (pipe(fd) < 0)
	{
		perror("ERROR: Failed to create a pipe\n");
		exit(EXIT_FAILURE);
	}
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror("ERROR: Failed to create a pipe\n");
		exit(EXIT_FAILURE);
	}
}

void	apply_pipe(t_arg *arg)
{
	int	pipe_fd[2];
	int	pid;
	int	index;

	index = 0;
	while (index < arg->command_count)
	{
		create_pipe(pipe_fd);
		pid = fork();
		if (pid == -1)
		{
			perror("ERROR: Failed to create a fork\n");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
			child_process(arg, pipe_fd, index);
		else
			parent_process(arg, pipe_fd);
		index++;
	}
	index = 0;
	while (index++ < arg->command_count)
		waitpid(-1, NULL, 0);
}
```
First, create a pipe using the  
Second, create a child_process with fork()  
Finally, handle child and parent processes separately  

### child_process
```c
static void	first_command(t_arg *arg, int pipe_fd[2])
{
	if (arg->here_doc == 1)
	{
		dup2(arg->tmp_fd, STDIN_FILENO);
		close(arg->tmp_fd);
	}
	else if (arg->infile_str != NULL)
	{
		if (open_input_file(arg) == ERROR)
			open_error_exit("ERROR : Not opened input file");
		dup2(arg->input_fd, STDIN_FILENO);
		close(arg->input_fd);
	}
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execve(arg->full_path, arg->current_command, NULL);
}

static void	middle_command(t_arg *arg, int pipe_fd[2])
{
	dup2(arg->prev_fd, STDIN_FILENO);
	close(arg->prev_fd);
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	execve(arg->full_path, arg->current_command, NULL);
}

static void	apply_first_in_last(t_arg *arg)
{
	if (arg->here_doc == 1)
	{
		dup2(arg->tmp_fd, STDIN_FILENO);
		close(arg->tmp_fd);
	}
	else if (arg->infile_str != NULL)
	{
		if (open_input_file(arg) == ERROR)
			open_error_exit("ERROR : Not opened input file");
		dup2(arg->input_fd, STDIN_FILENO);
		close(arg->input_fd);
	}
}

static void	last_command(t_arg *arg, int pipe_fd[2], int index)
{
	if (index == 0)
		apply_first_in_last(arg);
	else
	{
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		dup2(arg->prev_fd, STDIN_FILENO);
		close(arg->prev_fd);
	}
	if (arg->here_doc == 1)
	{
		if (open_heredoc_output_file(arg) == ERROR)
			open_error_exit("ERROR: Not opened here_doc output file\n");
	}
	else
	{
		if (open_output_file(arg) == ERROR)
			open_error_exit("ERROR: Not opened output file\n");
	}
	dup2(arg->output_fd, STDOUT_FILENO);
	close(arg->output_fd);
	execve(arg->full_path, arg->current_command, NULL);
}

void	child_process(t_arg *arg, int pipe_fd[2], int index)
{
	if (set_commands(arg, index) == ERROR)
		exit(1);
	if (index == 0 && arg->command_count > 1)
		first_command(arg, pipe_fd);
	else if (index > 0 && index < arg->command_count - 1)
		middle_command(arg, pipe_fd);
	if (index == arg->command_count - 1)
		last_command(arg, pipe_fd, index);
}
```
First command, take a value from infile or here_doc and output to a pipe  
Second command, take a value from a previous pipe and output to this pipe  
Last command, take the value of the previous pipe and output to output_file

### parent_process
```c
void	parent_process(t_arg *arg, int pipe_fd[2])
{
	close(arg->prev_fd);
	close(pipe_fd[1]);
	arg->prev_fd = pipe_fd[0];
}
```
First, close the fd from the previous pipe
Second, save the fd to be used by the next child process in arg->prev_fd