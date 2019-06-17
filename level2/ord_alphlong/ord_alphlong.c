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

#include <stdlib.h>
#include <unistd.h>

#define BL_SP(ch) (ch == 32 || ch == 9)
#define BL_UP(ch) (ch >= 65 && ch <= 90)
#define LOWER(ch) (ch + (BL_UP(ch) ? 32 : 0))

typedef struct s_node t_node;
struct s_node
{
	int		n;
	char	*str;
	t_node	*left;
	t_node	*right;
};

int ft_length_word(const char *s)
{
	int ret;

	ret = 0;
	while (s[ret] && !BL_SP(s[ret]))
		ret++;
	return (ret);
}

int ft_strncmp(const char *s1, const char *s2, int n)
{
	while (LOWER(*s1) == LOWER(*s2) && *s1 && *s2 && n--)
	{
		s1++;
		s2++;
	}
	if (!n)
		return (0);
	return (LOWER(*s1) - LOWER(*s2));
}

t_node	*ft_node_create(const char *s, int n)
{
	t_node *ret;

	ret = (t_node*)malloc(sizeof(t_node));
	if (!ret)
		return (NULL);
	ret->n = n;
	ret->str = (char*)s;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}

int		ft_node_print(t_node *list, int pt)
{

	if (!list)
		return (pt);
	pt = ft_node_print(list->left, pt);
	if (pt && pt < list->n)
		write(1, "\n", 1);
	else if (pt == list->n)
		write(1, " ", 1);
	write(1, list->str, list->n);
	pt = list->n;
	pt = ft_node_print(list->right, pt);
	return (pt);
}

t_node	*ft_node_insert(t_node *list, const char *s, int n)
{
	if (!list)
	{
		list = ft_node_create(s, n);
		return (list);
	}
	if (n > list->n || (n == list->n && ft_strncmp(s, list->str, n) >= 0))
		list->right = ft_node_insert(list->right, s, n);
	if (n < list->n || (n == list->n && ft_strncmp(s, list->str, n) < 0))
		list->left = ft_node_insert(list->left, s, n);
	return (list);
}

int main(int ac, char **av)
{
	t_node *list;
	int n;

	if (ac == 2)
	{
		list = NULL;
		while (*av[1])
		{
			n = ft_length_word(av[1]);
			list = ft_node_insert(list, av[1], n);
			av[1] += n;
			av[1] += (*av[1] ? 1 : 0);
		}
		ft_node_print(list, 0);
	}
	write(1, "\n", 1);
	return (0);
}
