/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:11:57 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/07 11:11:59 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printnum(int n)
{
	int		i;
	long	k;

	i = 0;
	k = n;
	ft_putnbr_fd(n, 1);
	if (k < 0)
	{
		k = -k;
		i++;
	}
	else if (k == 0)
		return (1);
	while (k > 0)
	{
		k /= 10;
		i++;
	}
	return (i);
}
/*int main ()*/
/*{*/
/*	printf("%d", ft_printnum(1));*/
/*}*/
