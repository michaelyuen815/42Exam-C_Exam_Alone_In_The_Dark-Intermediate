/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 21:30:55 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/17 21:57:33 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node *cur_lst1;
	struct s_node *cur_lst2;

	cur_lst1 = lst1;
	while (cur_lst1)
	{
		cur_lst2 = lst2;
		while (cur_lst2)
		{
			if (cur_lst1 == cur_lst2)
				return (cur_lst1);
			cur_lst2 = cur_lst2->next;
		}
		cur_lst1 = cur_lst1->next;
	}
	return (NULL);
}
