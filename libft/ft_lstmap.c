/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:23 by jpatrici          #+#    #+#             */
/*   Updated: 2024/11/05 17:13:00 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*no;
	void	*temp;

	if (!lst || !f || !del)
		return (0);
	n = NULL;
	while (lst)
	{
		temp = f(lst->content);
		no = ft_lstnew(temp);
		if (no == NULL)
		{
			ft_lstclear(&n, (del));
			del(temp);
			return (0);
		}
		ft_lstadd_back(&n, no);
		lst = lst->next;
	}
	return (n);
}
