/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:39:08 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/24 16:24:22 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		n;
	int		k;

	i = 0;
	k = -1;
	j = ft_strlen(s1) - 1;
	while (j >= i && s1[++k])
	{
		n = -1;
		while (j >= i && set[++n] != '\0')
		{
			if (j > i && s1[i] == set[n])
				i++;
			if (j > i && s1[j] == set[n])
				j--;
			if (j == i && s1[i] == set[n])
				return (ft_calloc(1, 1));
		}
	}
	return (ft_substr((char *)s1, i, ((j + 1) - i)));
}
/*
int		main()
{
	char	*str = "   xxx   xxx";
	char	*set = " x";
	char	*r = "";
	char	*s = ft_strtrim(str, set);

	printf("%s\n", s);
	printf("%s\n", r);
}*/
