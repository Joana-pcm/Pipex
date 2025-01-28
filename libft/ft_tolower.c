/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:10:58 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/21 14:13:26 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	else
		return (c);
}
/*
int main ()
{
	printf("%c\n%c\n%c\n%c\n%c\n", ft_tolower('a'),
       	ft_tolower('B'), ft_tolower('m'),
       	ft_tolower('5'), ft_tolower('-'));
}*/
