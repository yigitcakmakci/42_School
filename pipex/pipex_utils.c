/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycakmakc <ycakmakc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 20:45:07 by ycakmakc          #+#    #+#             */
/*   Updated: 2025/11/03 02:53:40 by ycakmakc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void	free_list(char **trash)
{
	int	i;

	i = 0;
	while (trash && trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}

char	*try_path(char **envp, char *cmd)
{
	char	*test_path;
	int		i;
	char	*res;

	i = 0;
	test_path = ft_strjoin("/", cmd);
	while (envp[i])
	{
		res = ft_strjoin(envp[i], test_path);
		if (!res)
		{
			free(test_path);
			perror("pipex: str_join > res");
			return (0);
		}
		if (access(res, X_OK) == 0)
		{
			free(test_path);
			return (res);
		}
		free(res);
		i++;
	}
	free(test_path);
	return (0);
}

char	*set_path(char **envp, char *cmd)
{
	int		i;
	char	**paths_array;
	char	*result_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
		{
			paths_array = ft_split(envp[i] + 5, ':');
			if (!paths_array)
				return (0);
			result_path = try_path(paths_array, cmd);
			free_list(paths_array);
			return (result_path);
		}
		i++;
	}
	return (0);
}

void	executes(char **argv, char **envp, int which_process)
{
	char	*path;
	char	**cmd;

	if (which_process)
		cmd = ft_split(argv[2], ' ');
	else
		cmd = ft_split(argv[3], ' ');
	if (!cmd)
	{
		exit(1);
	}
	path = set_path(envp, cmd[0]);
	if (!path)
	{
		perror("pipex: komut dizini bulunamadı");
		free(path);
		free_list(cmd);
		exit(127);
	}
	execve(path, cmd, envp);
}
