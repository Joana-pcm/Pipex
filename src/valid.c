/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:57:42 by jpatrici          #+#    #+#             */
/*   Updated: 2025/02/03 16:59:30 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	valid_input(t_pipex **pipex, char **av, char **envp, int size)
{
	int		j;
	char	**paths;

	j = -1;
	if (size != 5)
		return (0);
	if (access(av[1], R_OK) == -1)
		return (0);
	if (av[1] == NULL || av[2] == NULL)
		return (0);
	paths = NULL;
	while (envp[++j])
		if (ft_strnstr(envp[j], "PATH=", 5))
			paths = ft_split(&envp[j][5], ':');
	if (!paths)
		return (free_error(pipex, "ERROR"));
	return (setcmds(pipex, av, paths, size));
}

int	setcmds(t_pipex **pipex, char **av, char **paths, int size)
{
	int		j;
	int		n;
	int		i;
	char	*temp;

	n = 0;
	j = -1;
	i = 2;
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
		free_loop(temp, &(*pipex)->paths[n], &(*pipex)->cmds[n], j);
	}
	free_array(paths);
	if (!(*pipex)->paths[i - 1] || access((*pipex)->paths[i - 1], F_OK) == -1)
		return (0);
	return (((i == n)));
}

int	free_error(t_pipex **pipex, char *error)
{
	if ((*pipex)->paths)
	{
		free_array((*pipex)->paths);
		free_array((*pipex)->cmds);
	}
	else
	{
		free((*pipex)->paths);
		free((*pipex)->cmds);
	}
	free((*pipex));
	if (error != NULL)
		perror(error);
	return (1);
}

void	free_loop(char *s, char **paths, char **cmds, int j)
{
	if (s)
		free(s);
	if (j != -1 && *paths)
	{
		free(*paths);
		*paths = NULL;
	}
	if (j != -1 && *cmds)
	{
		free(*cmds);
		*cmds = NULL;
	}
}

int	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i] != NULL)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
	return (0);
}
