/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:45:49 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/17 16:11:24 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void	parent_process(char **argv, char **envp, int *fd)
{
	int	output_fd;

	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("pipex: dup2 output");
		exit(1);
	}
	output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror("pipex: output file");
		exit(1);
	}
	if (dup2(output_fd, STDOUT_FILENO) == -1)
	{
		perror("pipex: dup2 input");
		exit(1);
	}
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
	if (input_fd == -1)
	{
		perror("pipex: input file");
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

static void	run_pipeline(char **argv, char **envp, int *fd)
{
	pid_t	pid;
	pid_t	pid2;

	pid = fork(); //2
	if (pid == -1)
	{
		perror("pipex: fork1");
		exit(1);
	}
	if (pid == 0)
		child_process(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
	{
		perror("pipex: fork2");
		exit(1);
	}
	if (pid2 == 0)
		parent_process(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc != 5)
		return (0);
	if (pipe(fd) == -1)
	{
		perror("pipex: pipe");
		exit(1);
	}
	run_pipeline(argv, envp, fd);
	return (0);
}
