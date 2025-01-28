/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:47:39 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/04 16:33:01 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	a;
	unsigned int	i;

	i = -1;
	a = (unsigned char) c;
	p = (unsigned char *) s;
	while (n-- > 0)
	{
		if (p[++i] == a)
			return ((void *)&p[i]);
	}
	return (0);
}
/*
int main()
{
	char s[] = "hello";
	char *buf;

	buf = ft_memchr(s, 'e', 3);
	printf("%s\n", buf);
	buf =ft_memchr(s, 'l', 5);
	printf("%s\n", buf);
	buf =ft_memchr(s, '\0', 5);
	printf("%s\n", buf);
}*/
