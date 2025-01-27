/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:57:42 by jpatrici          #+#    #+#             */
/*   Updated: 2025/01/22 16:56:12 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

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
	open(av[size - 1], O_WRONLY | O_CREAT , 0777);
	return (1);
}

int	valid_cmds(t_pipex **pipex, char **av, char **envp, int size)
{
	int		i;
	int		j;
	char	**paths;

	j = -1;
	i = 2 + ((*pipex)->here_doc);
	paths = NULL;	
	while (envp[++j])
		if (ft_strnstr(envp[j], "PATH=", 5))
			paths = ft_split(&envp[j][5], ':');
	return (setcmds(pipex, av, paths, size));
}

int	setcmds(t_pipex  **pipex, char **av, char **paths, int size)
{
	int	j;
	int	n;
	int	i;
	char	*temp;

	n = 0;
	j = -1;
	i = 2 + ((*pipex)->here_doc);
	while (paths[++j] && i + n < size - 1)
	{
		temp = ft_substr(av[i + n], 0, ft_strchrlen(av[i + n], ' '));
		(*pipex)->cmds[n] = ft_strdup(av[i + n]);
		(*pipex)->paths[n] = ft_strjoin(paths[j], "/");
		(*pipex)->paths[n] = ft_strjoin_gnl((*pipex)->paths[n], temp);
		if (access((*pipex)->paths[n], F_OK) != -1
			&& open((*pipex)->paths[n], O_DIRECTORY) == -1
			&& ++n)
			j = -1;
	}
	(*pipex)->cmds[n + 1] = NULL;
	if (access((*pipex)->paths[i - 1], F_OK) == -1)
		return (0);
	return (((size - (i + 1)) == n));
}

int	free_error(t_pipex **pipex, char *error)
{
	printf("%s\n", error);
	(void) pipex;
	(void) error;
	return (5);
}

int	valid_args(t_pipex **pipex, char **av,char **envp, int size)
{
	(void) pipex;
	(void) av;
	(void) envp;
	(void) size;
	return 4;
}
