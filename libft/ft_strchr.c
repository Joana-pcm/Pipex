/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:14:02 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/21 14:46:13 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = -1;
	p = (char *) s;
	while (p[++i] != '\0')
	{
		if (p[i] == (unsigned char) c)
			return (&p[i]);
	}
	if (p[i] == (unsigned char) c)
		return (&p[i]);
	else
		return (0);
}
/*
int main()
{
	char * s = "hello";
	printf("%s\n%s\n%s\n",
       	ft_strchr(s, 'e'), ft_strchr(s, 'l'), ft_strchr(s, '\0'));
	printf("%p\n%p\n%p\n", 
	ft_strchr(s, 'e'), ft_strchr(s, 'l'), ft_strchr(s, '\0'));
}*/
