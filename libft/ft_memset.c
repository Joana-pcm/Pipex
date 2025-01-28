/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:38:58 by jpatrici          #+#    #+#             */
/*   Updated: 2024/10/17 17:21:39 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr++ = c;
		n--;
	}
	return (s);
}
/*
#include <string.h>
#define  BUF_SIZE  20
 
int main(void)
{
   char buffer[BUF_SIZE + 1];
   char *string;
char str[50] = "42 is for programming geeks.";
    printf("\nBefore memset(): %s\n", str);

    // Fill 8 characters starting from str[13] with '.'
    ft_memset(str + 3, '.', 7*sizeof(char));
    printf("After ft_memset():  %s\n", str);
    memset(str + 3, '.', 7*sizeof(char));

    printf("After memset():  %s", str);
//test the og memset 
   memset(buffer, 0, sizeof(buffer));
   string  = (char *) memset(buffer,'A', 10);
   printf("\nBuffer contents: %s\n", string);
   memset(buffer+10, 'B', 10);
   printf("\nBuffer contents: %s\n", buffer);
//mine
   ft_memset(buffer, 0, sizeof(buffer));
   string = (char *) ft_memset(buffer,'A', 10);
   printf("\nft_Buffer contents: %s\n", string);
   ft_memset(buffer+10, 'B', 10);
   printf("\nft_Buffer contents: %s\n", buffer);
}*/
