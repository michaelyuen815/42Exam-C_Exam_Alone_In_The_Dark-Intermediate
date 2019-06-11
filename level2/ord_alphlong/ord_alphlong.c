/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:27:42 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/09 23:47:55 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ord_alphlong.h"



t_list *ft_list_new(char *str, int len)
{
	t_list *ret;

	ret = malloc(sizeof(t_list));
	ret->len = len;
	ret->next = NULL;
	ret->str = malloc(sizeof(t_string));
	ret->str->str = str;
	ret->str->next = NULL;
	return (ret);
}

t_string *ft_string_init(t_string *t_str, char *str, int len)
{
	t_string *t_cur;
	t_string *t_tmp;

	if (ft_strncmp(t_str->str, str, len) > 0)
	{
		t_tmp = malloc(sizeof(t_string));
		t_tmp->str = str;
		t_tmp->next = t_str;
		t_str = t_tmp;
	}
	else
	{
		t_cur = t_str;
		while (t_cur->next)
		{
			if (ft_strncmp(t_str->next->str, str, len) > 0)
				break;
			t_cur = t_cur->next;
		}
		t_tmp = t_cur->next;
		t_cur->next = malloc(sizeof(t_string));
		t_cur->next->str = str;
		t_cur->next->next = t_tmp;
	}
	return (t_str);
}

t_list *ft_list_init(t_list *list, char *str, int len)
{
	t_list *tmp;
	t_list *tgt;

	if (!list)
		list = ft_list_new(str, len);
	else
	{
		tmp = list;
		if (list->len > len)
		{
			tgt = ft_list_new(str, len);
			tgt->next = list;
			list = tgt;
		}
		else
		{
			while (tmp->next)
			{
				if (tmp->next->len > len)
					break;
				tmp = tmp->next;
			}
			if (tmp->len == len)
				tmp->str = ft_string_init(tmp->str, str, len);
			else
			{
				tgt = tmp->next;
				tmp->next = ft_list_new(str, len);
				tmp->next->next = tgt;
			}
		}
	}
	
	return (list);
}

int main(int ac, char **av)
{
	t_list *list;
	t_string *str;
	char *tmp;
	int len;

	list = NULL;
	if (ac == 2)
	{
		if (*av[1])
		{
			while (*av[1])
			{
				tmp = ft_strchr(av[1], ' ');
				len = tmp ? (int)(tmp - av[1]) : ft_strlen(av[1]);
				list = ft_list_init(list, av[1], len);
				av[1] += len; 
				if (*av[1])
					av[1]++;
			}
			while (list)
			{
				str = list->str;
				while (str)
				{
					write(1, str->str, list->len);
					str = str->next;
					if (str)
						write(1, " ", 1);
				}
				write(1, "\n", 1);
				list = list->next;
			}
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
