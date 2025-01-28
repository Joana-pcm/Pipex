/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:23:29 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/08 14:27:12 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printstr(char *s)
{
	int	count;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (count);
}
