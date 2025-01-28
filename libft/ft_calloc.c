/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:41:04 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/23 12:47:35 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = -1;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (++i < count * size)
	{
		ptr[i] = 0;
	}
	return (ptr);
}
/*
int main()
{
	unsigned char *ptr;
	ptr = ft_calloc(2, 2);
	free(ptr);
	ptr = calloc(2, 2);
	free(ptr);
}
*/
