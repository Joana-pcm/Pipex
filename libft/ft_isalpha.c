/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:24:54 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/16 10:58:58 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (c);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isalpha('c'));
	printf("%d\n", isalpha('c')); 
	printf("%d\n", ft_isalpha('A'));
	printf("%d\n", isalpha('A')); 
	printf("%d\n", ft_isalpha('9'));
	printf("%d\n", isalpha('9')); 
	printf("%d\n", ft_isalpha(' '));
	printf("%d\n", isalpha(' '));
}*/
