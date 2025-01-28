/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:55:40 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/11 14:55:42 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_printad(unsigned long long n)
{
	int		count;

	count = 0;
	if (n < 16)
		count += write(1, &"0123456789abcdef"[n], 1);
	if (n >= 16)
	{
		count += ft_printad(n / 16);
		count += ft_printad(n % 16);
	}
	return (count);
}

int	ft_printptr(unsigned long long n)
{
	int		count;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 2;
	write(1, "0x", 2);
	count += ft_printad(n);
	return (count);
}
