/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:19:38 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/13 13:36:37 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printunint(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
	{
		count += ft_printunint(n / 10);
		count += ft_printunint(n % 10);
	}
	if (n < 10)
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	return (count);
}
