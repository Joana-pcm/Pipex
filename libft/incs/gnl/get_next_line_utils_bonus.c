/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:53:53 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/21 15:07:43 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strchrlen(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (start > (unsigned int)ft_strchrlen((char *)s, '\0'))
	{
		return (NULL);
	}
	if (len > (ft_strchrlen((char *)s, '\0') - start))
		str = (char *) malloc((ft_strchrlen((char *)s, '\0') - start) + 1);
	else if (ft_strchrlen((char *) s, '\0') == 0)
		return (NULL);
	else
		str = (char *) malloc((len) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s[start] != '\0' && len > 0)
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*s2;
	int		i;

	i = ft_strchrlen((char *)s, '\0');
	s2 = malloc((i + 1) * sizeof(char));
	if (!s2)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		s2[i] = s[i];
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*p;

	i = -1;
	if (!s)
		return (NULL);
	p = (char *) s;
	while (p[++i] != '\0')
	{
		if ((unsigned char) p[i] == (unsigned char) c)
			return ((char *)&p[i]);
	}
	if ((unsigned char) p[i] == (unsigned char) c)
		return ((char *)&p[i]);
	else
		return (0);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*joint;

	i = -1;
	j = -1;
	if ((ft_strchrlen((char *) s1, '\0') + \
		ft_strchrlen((char *) s2, '\0')) == 0)
	{
		free((char *)s1);
		return (NULL);
	}
	joint = (char *) malloc((ft_strchrlen((char *)s1, '\0') + \
					ft_strchrlen((char *)s2, '\0') + 1) * sizeof(char ));
	if (!joint)
		return (NULL);
	while (s1[++i])
		joint[i] = s1[i];
	while (s2[++j])
		joint[i++] = s2[j];
	joint[i] = '\0';
	free((char *)s1);
	return (joint);
}
