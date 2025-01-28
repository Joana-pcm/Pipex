/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:33:25 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/30 11:33:16 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*s;
	int		count;

	sign = n;
	count = len(n);
	if (n <= 0)
		count++;
	s = malloc((++count) * sizeof(char));
	if (!s)
		return (0);
	s[--count] = '\0';
	s[--count] = (((n % 10) < 0) * -(n % 10) \
		+ ((n % 10) >= 0) * (n % 10)) + '0';
	n /= 10;
	while (n != 0)
	{
		s[--count] = (((n % 10) < 0) * -(n % 10) \
			+ ((n % 10) >= 0) * (n % 10)) + '0';
		n /= 10;
	}
	if (sign < 0)
		s[--count] = '-';
	return (s);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(-1326136181));
} */
