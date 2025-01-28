/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:09:34 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/06 16:29:17 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
//#include <limits.h>
//#define LONG_MIN  (-__LONG_MAX__ -1L)

static	int	ft_check(char *s, int i, va_list p)
{
	if (s[i] == 'd' || s[i] == 'i')
		return (ft_printnum(va_arg(p, int)));
	else if (s[i] == 'u')
		return (ft_printunint(va_arg(p, unsigned int)));
	else if (s[i] == 's')
		return (ft_printstr(va_arg(p, char *)));
	else if (s[i] == 'c')
		return (ft_printchr(va_arg(p, int)));
	else if (s[i] == 'p')
		return (ft_printptr(va_arg(p, unsigned long long)));
	else if (s[i] == 'x' || s[i] == 'X')
		return (ft_printhex(va_arg(p, unsigned int), \
				(s[i] > 'X')));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	p;

	i = -1;
	count = 0;
	va_start(p, s);
	while (s[++i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%' && ++count)
				write(1, &s[++i], 1);
			else
				count += ft_check((char *)s, ++i, p);
		}
		else
			count += write(1, &s[i], 1);
	}
	va_end(p);
	return (count);
}
/*
int main()
{
	int i = 255;
	ft_printf("----test basic input:----\n");
	int test = ft_printf("str:\thello %s\ndigit:\t%d\n\
int:\t%i\nchr:\t%c\nptr:\t%p\nhex:\t%x\nper:\t%%\n",\
"world", 10, 1234, 'B', &test, i);
	ft_printf("\nlen:\t%d\n-------------------------\n", test);
	test = printf("str:\thello %s\ndigit:\t%d\n\
int:\t%i\nchr:\t%c\nptr:\t%p\nhex:\t%x\nper:\t%%\n",\
"world", 10, 1234, 'B', &test, i);
	printf("\nlen:\t%d\n\n", test);

	ft_printf("-------test NULLs:-------\n");
	test = ft_printf("str:\thello %s\ndigit:\t%d\n\
int:\t%i\nchr:\t%c\nptr:\t%p\nhex:\t%X\n",\
(char *)NULL, 0, INT_MIN, 'B', NULL, LONG_MIN);
	ft_printf("\nlen:\t%d\n-------------------------\n", test);
	test = printf("str:\thello %s\ndigit:\t%d\n\
int:\t%i\nchr:\t%c\nptr:\t%p\nhex:\t%lX\n",\
(char *)NULL, 0, INT_MIN, 'B', NULL, LONG_MIN);
	printf("\nlen:\t%d\n\n", test);
}*/
