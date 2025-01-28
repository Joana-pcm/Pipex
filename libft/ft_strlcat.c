/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:13:24 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/21 13:37:08 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	slength;

	i = 0;
	j = 0;
	slength = 0;
	while (src[slength] != '\0')
		slength++;
	while (dest[j] != '\0')
		j++;
	if (size == 0 || j >= size)
		return (slength + size);
	while (src[i] != '\0' && i < size - j - 1)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (j + slength);
}
