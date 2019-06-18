/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:51:42 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/17 18:52:14 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define NUM(ch) (ch >= 48 && ch <= 57)

struct s_node
{
	int val;
	int nb;
	struct s_node **next;
};

int ft_insert(struct s_node *main, struct s_node *cur)
{
	int i;
	int ret;
	struct s_node **next;

	if (!main)
		return (0);
	ret = 0;
	if (main->val == cur->val)
	{
		i = -1;
		while (++i < main->nb)
			if (main->next[i]->val == cur->next[0]->val)
				break;
		if (i == main->nb)
		{
			ret = 1;
			next = malloc(sizeof(struct s_node) * (main->nb + 1));
			i = -1;
			while (++i < main->nb)
				next[i] = main->next[i];
			next[i] = cur;
			main->nb++;
			free(main->next);
			main->next = next;
		}
		else
			ret = -1;
	}
	else
	{
		i = -1;
		while (++i < main->nb)
			ret += ft_insert(main->next[i], cur);
	}
	return (ret);
}

struct s_node *ft_create(char **s)
{
	int a;
	int b;
	struct s_node *ret;

	if (!(ret = (struct s_node *)malloc(sizeof(struct s_node))))
		return (NULL);
	a = 0;
	b = 0;
	while (NUM(**s))
		a = a * 10 + *(*s)++ - '0';
	(*s)++;
	while (NUM(**s))
		b = b * 10 + *(*s)++ - '0';
	(*s)++;
	ret->nb++;
	ret->next = malloc(sizeof(struct s_node));
	ret->next[0]->nb = 0;
	ret->next[0]->next = NULL;
	if (a > b)
	{
		ret->val = b;
		ret->next[0]->val = a;
	}
	else
	{
		ret->val = a;
		ret->next[0]->val = b;
	}
	return (ret);
}

int main(int ac, char **av)
{
	int i;
	int j;
	int chk;
	struct s_node *list[2048];
	struct s_node *cur;
	struct s_node *tmp;

	if (ac == 2)
	{
		i = 0;
		list[0] = NULL;
		while (*av[1])
		{
			cur = ft_create(&av[1]);
			if (!i)
				list[i++] = cur;
			else if (cur->next[0]->val == list[0]->val)
			{
				cur->next[0]->nb = list[0]->nb;
				cur->next[0]->next = list[0]->next;
				tmp = list[0];
				list[0] = cur;
				free(tmp);
			}
			else if (!ft_insert(list[0], cur))
				list[i++] = cur;
		}
		chk = 1;
		while (chk)
		{
			chk = 0;
			j = 0;
			while (++j < i)
			{
				if (list[j])
				{
					if (list[j]->next[0]->val == list[0]->val)
					{
						list[j]->next[0]->nb = list[0]->nb;
						list[j]->next[0]->next = list[0]->next;
						tmp = list[0];
						list[0] = list[j];
						free(tmp);
						list[j] = NULL;
						chk = 1;
					}
					else
					{
						chk |= (ft_insert(list[0], list[j]) == 1);
					}
				}
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
