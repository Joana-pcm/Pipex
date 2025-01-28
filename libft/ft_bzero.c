/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:22:18 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/18 10:42:21 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr++ = 0;
		n--;
	}
}
/*
#include <string.h>

int main(void)
{
  char buffer[21] = "hello";
   char str[50] = "42 is for programming geeks.";
    printf("\nBefore bzero(): %s\n", str);

// Fill 8 characters starting from str[13] with '.'
    ft_bzero(str + 2, 7*sizeof(char));
    printf("After ft_bzero():  %s\n", str);
    bzero(str + 2, 7*sizeof(char));

    printf("After bzero():  %s", str);
//test the og bzero
   bzero(buffer, 10);
   printf("\nBuffer contents: %s\n", buffer);
   bzero(buffer+10, 10);
   printf("\nBuffer contents: %s\n", buffer);
//mine
   ft_bzero(buffer, 10);
   printf("\nft_Buffer contents: %s\n", buffer);
   ft_bzero(buffer+10, 10);
   printf("\nft_Buffer contents: %s\n", buffer);
}*/
