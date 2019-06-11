/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:08:18 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 16:08:20 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

struct s_node {
	int value;
	struct s_node *next;
};

int is_looping(struct s_node *node)
{
	struct s_node *t_node;
	struct s_node *t_nw_node;
	struct s_node *t_nw_chk;
	struct s_node *t_tmp;

	t_node = node;
	t_nw_node = NULL;
	t_nw_chk = NULL;
	while (t_node)
	{
		if (!t_nw_node)
		{
			t_nw_node = t_node;
			t_nw_chk = t_node;
			t_node = t_node->next;
			t_nw_chk->next = NULL;
		}
		else if (t_node < t_nw_node)
		{
			t_tmp = t_node;
			t_node = t_node->next;
			t_tmp->next = t_nw_node;
			t_nw_node = t_tmp;
		}
		else
		{
			if (t_node < t_nw_chk)
				t_nw_chk = t_nw_node;
			while (t_nw_chk->next <= t_node && t_nw_chk->next)
				t_nw_chk = t_nw_chk->next;
			if (t_node == t_nw_chk)
				return (0);
			t_tmp = t_nw_chk->next;
			t_nw_chk->next = t_node;
			t_node = t_node->next;
			t_nw_chk = t_nw_chk->next;
			t_nw_chk->next = t_tmp;
		}
	}
	return (1);
}