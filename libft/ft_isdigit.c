/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:04:47 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/16 11:21:32 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isdigit('c'));
	printf("%d\n", isdigit('c'));
	printf("%d\n", ft_isdigit('A'));
	printf("%d\n", isdigit('A'));
	printf("%d\n", ft_isdigit('9'));
	printf("%d\n", isdigit('9'));
	printf("%d\n", ft_isdigit(' '));
	printf("%d\n", isdigit(' '));
}*/
