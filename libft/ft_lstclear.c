/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:59:41 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/05 15:14:47 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	p = *lst;
	while ((*lst))
	{
		p = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = p;
	}
	free(*lst);
	*lst = NULL;
}
