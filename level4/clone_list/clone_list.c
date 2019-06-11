/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:37:11 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 10:59:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *ft_create(struct s_node *src)
{
	struct s_node *ret;

	if (!(ret = malloc(sizeof(struct s_node))))
		return (NULL);
	ret->data = src->data;
	ret->next = NULL;
	ret->other = NULL;
	return (ret);
}

struct s_node *clone_list(struct s_node *node)
{
	struct s_node *ret;
	struct s_node *r_cur;
	struct s_node *r_find;
	struct s_node *s_cur;
	struct s_node *s_find;

	if (!node)
		return (NULL);
	s_cur = node;
	ret = ft_create(node);
	r_cur = ret;
	while (s_cur->next)
	{
		r_cur->next = ft_create(s_cur->next);
		r_cur = r_cur->next;
		s_cur = s_cur->next;
	}
	s_cur = node;
	r_cur = ret;
	while (s_cur)
	{
		if (s_cur->other == s_cur)
			r_cur->other = r_cur;
		else if (s_cur->other)
		{
			s_find = node;
			r_find = ret;
			while (s_cur->other != s_find)
			{
				s_find = s_find->next;
				r_find = r_find->next;
			}
			r_cur->other = r_find;
		}
		s_cur = s_cur->next;
		r_cur = r_cur->next;
	}
	return (ret);
}
