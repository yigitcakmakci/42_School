/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:45:49 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/01 18:52:29 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void	parent_process(char **argv, char **envp, int *fd)
{
	int	output_fd;

	dup2(fd[0], STDIN_FILENO);
	output_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	close(fd[0]);
	close(fd[1]);
	executes(argv, envp, 0);
}
static void	child_process(char **argv, char **envp, int *fd)
{
	int	input_fd;

	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("pipex: dup2 output");
		exit(1);
	}
	input_fd = open(argv[1], O_RDONLY);
	if ((input_fd = open(argv[1], O_RDONLY, 0777)) == -1)
	{
		perror("pipex: output file");
		exit(1);
	}
	if (dup2(input_fd, STDIN_FILENO) == -1)
	{
		perror("pipex: dup2 input");
		exit(1);
	}
	close(input_fd);
	close(fd[0]);
	close(fd[1]);
	executes(argv, envp, 1);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t pid;
	int fd[2];

	if (argc != 5)
	{
		write(1, "WROGN ARGUMENT!\n", 16);
		return (0);
	}
	pipe(fd);
	pid = fork();
	if (pid == -1)
		write(1, "ERROR\n", 7);
	if (pid == 0)
		child_process(argv, envp, fd);
	else
	{
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
}