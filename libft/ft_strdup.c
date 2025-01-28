/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:50:30 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/23 13:12:46 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	i = ft_strlen(s);
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);
}
/*
int	main()
{
	char	*src = "Hello";
	printf("%s", ft_strdup(src));
	return (0);
}*/
