/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:31:14 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/24 15:27:50 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joint;

	i = -1;
	j = -1;
	joint = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char ));
	if (!joint)
		return (NULL);
	while (s1[++i])
		joint[i] = s1[i];
	while (s2[++j])
		joint[i++] = s2[j];
	joint[i] = '\0';
	return (joint);
}
/*
int		main()
{
	char	*s1 = "hello";
	char	*s2 = ", world";
	char	*s = ft_strjoin(s1, s2);

	printf("%s\n", s);
}*/
