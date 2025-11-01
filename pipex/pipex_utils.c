
#include <unistd.h>
#include <sys/types.h>

static char *try_path(char **envp, char *cmd)
{
    char	*test_path;
    int		i;

	i = 0;
    test_path = ft_strjoin("/", cmd);
    while (envp[i])
    {
		if (access(ft_strjoin(envp[i], test_path) ,X_OK) == 0)
			return (ft_strjoin(envp[i], test_path));
        i++;
    }
    return(0);
}

static char *set_path(char **envp, char *cmd)
{
    int i = 0;
    while(envp[i])
    {
        if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
            return try_path(ft_split(envp[i] + 5, ':'), cmd);
        i++;
    }
    return 0;
}

static void executes(char **argv, char **envp, int which_process)
{
    char *path;
    char **cmd;

	if (which_process)
		cmd = ft_split(argv[2], ' ');
	else
		cmd = ft_split(argv[3], ' ');
    path = set_path(envp, cmd[0]);
    execve(path, cmd, envp);
}