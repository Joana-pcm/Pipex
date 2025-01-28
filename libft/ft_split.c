/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:48:04 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/25 17:11:45 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count(char *s, char c)
{
	int	i;
	int	count;

	i = -1;
	if (s[0] != c && s[0] != '\0')
		count = 1;
	else
		count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
	}
	return (count);
}

static	void	*bfree(char	**ss)
{
	int	i;

	i = 0;
	while (ss[i])
	{
		free(ss[i]);
		i++;
	}
	free(ss);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ss;
	size_t	i;
	int		j;
	int		n;

	i = -1;
	j = -1;
	n = -1;
	ss = malloc(sizeof(char *) * (count((char *)s, c) + 1));
	if (!ss || !s)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && n < 0)
			n = i;
		else if ((s[i] == c || i == ft_strlen(s)) && n >= 0)
		{
			ss[++j] = ft_substr(s, n, (i - n));
			if (!ss[j])
				return (bfree(ss));
			n = -1;
		}
	}
	ss[++j] = NULL;
	return (ss);
}
/*
int	main()
{
	char	s [] = "";
	char	sep = ' ';
	int		i = 0;
	char	**s2 = ft_split(s, sep);
	if (s2[i] == 0)
		printf("fucked up\n");
	while (s2[i] != 0)
	{
		printf("%s\n", s2[i]);
		free(s2[i]);
		i++;
	}
	free(s2);
}*/
