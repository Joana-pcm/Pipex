#include "../inc/pipex.h"

int	valid_input(t_pipex **pipex, char **av, int size)
{
	int	i;

	i = 1;
	if (!ft_strncmp(av[1], "here_doc", 8))
		(*pipex)->here_doc = 1;
	if (size < (5 + ((*pipex)->here_doc)))
		return (0);
	if (access(av[i], F_OK) == -1 && (*pipex)->here_doc != 1)
		return (0);
	return (1);
}

int	valid_cmds(t_pipex **pipex, char **av, char **envp, int size)
{
	int	i;
	int j;
	int	n;
	char	**temp;

	n = -1;
	j = -1;
	i = 1 + ((*pipex)->here_doc);
	while (envp[++j])
		if (!ft_strnstr(envp[j], "PATH=", 5) && !envp[j][6])
			return (0);
	j = -1;
	while (av[++i] && envp[++j])
	{
		if (ft_strnstr(envp[j], av[i], ft_strlen(envp[j])))
		{
			(*pipex)->cmds[++n] = ft_strdup(av[i]);
			(*pipex)->paths[n] = ft_strjoin(envp[j], "/");
			temp = ft_split(av[i], ' ');
			(*pipex)->paths[n] = ft_strjoin(envp[j], temp[0]);	
		}
	}
	(void) size;
	return (1);
}

int	free_error(t_pipex **pipex, char *error)
{
	(void) pipex;
	(void) error;
	return (2);
}

int	valid_args(t_pipex **pipex, char **av,char **envp, int size)
{
	(void) pipex;
	(void) av;
	(void) envp;
	(void) size;
	return 2;
}
