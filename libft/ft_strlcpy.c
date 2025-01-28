/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:10:24 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/21 13:42:04 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	count;

	i = -1;
	count = ft_strlen(src);
	if (!dest && !src)
		return (0);
	if (count + 1 < size)
	{
		while (src[++i] != '\0' && i < size - 1)
			dest[i] = src[i];
		dest[i] = '\0';
	}
	else if (size != 0)
	{
		while (src[++i] != '\0' && i < size - 1)
			dest[i] = src[i];
		dest[size - 1] = '\0';
	}
	return (count);
}
/*
int	main()
{
	char	src [] = "aasdjj;s;sa";
	char	dest [100];
	printf("count: %zu\n", ft_strlcpy(dest, src, 100));
	printf("source: %s\n", src);
	printf("dest: %s\n", dest);
	return 0;
}*/
