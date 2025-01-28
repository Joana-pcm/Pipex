/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:06:20 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/08 15:49:33 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printhex(unsigned int n, int bi)
{
	int		count;

	count = 0;
	if (n < 16)
	{
		if (bi)
			count += write(1, &"0123456789abcdef"[n], 1);
		else
			count += write(1, &"0123456789ABCDEF"[n], 1);
	}
	if (n >= 16)
	{
		count += ft_printhex(n / 16, bi);
		count += ft_printhex(n % 16, bi);
	}
	return (count);
}
