/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:55:11 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/17 11:31:31 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isascii('c'));
	printf("%d\n", isascii('c'));
	printf("%d\n", ft_isascii('A'));
	printf("%d\n", isascii('A'));
	printf("%d\n", ft_isascii('9'));
	printf("%d\n", isascii('9'));
	printf("%d\n", ft_isascii(0));
	printf("%d\n", isascii(0));
}*/
