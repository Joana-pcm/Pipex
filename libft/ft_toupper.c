/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:50:55 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/21 14:08:50 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	else
		return (c);
}
/*
int main ()
{
	printf("%c\n%c\n%c\n%c\n%c\n", ft_toupper('a'),
       	ft_toupper('B'), ft_toupper('m'),
       	ft_toupper('5'), ft_toupper('-'));
}*/
