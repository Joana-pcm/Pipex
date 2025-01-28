/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:53:34 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/21 15:08:05 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*get_line(char **stash)
{
	char			*line;
	char			*keep;
	unsigned int	null;
	unsigned int	nl;

	nl = ft_strchrlen(*stash, '\n');
	nl += ((*stash)[nl] == '\n');
	line = ft_substr(*stash, 0, nl);
	if (!line)
		return (NULL);
	null = ft_strchrlen(*stash, '\0');
	keep = ft_substr(*stash, nl, (null - nl) + 1);
	if (!keep)
	{
		free(line);
		return (NULL);
	}
	free(*stash);
	*stash = keep;
	return (line);
}

static char	*get_stash(int fd, char *stash)
{
	char		*curr;
	ssize_t		bytes;

	bytes = 1;
	curr = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!curr)
		return (NULL);
	while (bytes > 0 && !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, curr, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(curr);
			free(stash);
			return (NULL);
		}
		curr[bytes] = '\0';
		stash = ft_strjoin(stash, curr);
	}
	free(curr);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 4096)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = ft_strdup("");
		if (!stash[fd])
			return (NULL);
	}
	stash[fd] = get_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(&stash[fd]);
	if (!stash[fd])
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	return (line);
}
