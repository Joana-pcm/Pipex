/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:22:16 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/16 11:30:03 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (c);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalnum('c'));
	printf("%d\n", isalnum('c'));
	printf("%d\n", ft_isalnum('A'));
	printf("%d\n", isalnum('A'));
	printf("%d\n", ft_isalnum('9'));
	printf("%d\n", isalnum('9'));
	printf("%d\n", ft_isalnum(' '));
	printf("%d\n", isalnum(' '));
}*/
