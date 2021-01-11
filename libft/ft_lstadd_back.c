/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 17:40:11 by mciupek           #+#    #+#             */
/*   Updated: 2020/11/23 17:53:54 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last_elem;

	if (!(*alst))
	{
		(*alst) = new;
		return ;
	}
	if (alst && new)
	{
		last_elem = ft_lstlast(*alst);
		last_elem->next = new;
	}
}
