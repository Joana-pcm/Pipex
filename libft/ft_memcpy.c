/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:43:06 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/18 12:21:52 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = dest;
	s = (unsigned char *) src;
	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	d[21];
	char	s[] = "hello world";
	
	bzero(d, 21);
	memcpy(d, s, 5);
	printf("\nOriginal: %s\n", d);
	bzero(d, 21);
	ft_memcpy(d, s, 5);
	printf("\nMine: %s\n", d);
}*/
