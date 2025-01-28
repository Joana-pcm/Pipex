/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:21:47 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/22 12:48:24 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	*gotcha;

	i = -1;
	gotcha = 0;
	p = (char *) s;
	while (p[++i] != '\0')
	{
		if (p[i] == (unsigned char) c)
			gotcha = &p[i];
	}
	if (p[i] == (unsigned char) c)
		gotcha = &p[i];
	return (gotcha);
}
/*
int main()
{
	char s[] = "hello";
	char *buf;

	buf = ft_strrchr(s, 'e');
	printf("%s\n%p\n", buf, buf);
	buf =ft_strrchr(s, 'l');
	printf("%s\n%p\n", buf, buf);
	buf =ft_strrchr(s, 'a');
	printf("%s\n%p\n", buf, buf);
}*/
