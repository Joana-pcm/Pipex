/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:27:35 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/23 10:20:15 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_atoi(const char *nptr)
{
	int	res;
	int	i;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (*nptr == '\010')
		return (0);
	while ((nptr[i] >= '\b' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	res *= sign;
	return (res);
}
/*
int	main()
{

		printf("%d", ft_atoi("\0 9"));
	return 0;
}*/
