/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:14:58 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 13:41:19 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_chk(char *str1, char *str2, int len)
{
	int i;
	int i_len;

	i = -1;
	while (str2[++i])
	{
		i_len = -1;
		while (++i_len < len)
		{
			if (str2[i + i_len] != str1[i_len])
				break;
			else if (i_len == len - 1)
				return (1);
		}
	}
	return (0);
}

int main(int ac, char **av)
{
	int i;
	int prefix;
	int len;
	int ret_prefix;
	int ret_len;

	if (ac > 1)
	{
		ret_prefix = 0;
		ret_len = 0;
		prefix = -1;
		while (av[1][++prefix])
		{
			len = 1;
			while (av[1][prefix + len - 1])
			{
				i = 1;
				while (++i < ac)
					if (!ft_chk(av[1] + prefix, av[i], len))
						break;
				if (i != ac)
					break;
				len++;
			}
			if (len - 1 > ret_len)
			{
				ret_len = len - 1;
				ret_prefix = prefix;
			}
		}
		write(1, av[1] + ret_prefix, ret_len);
	}
	write(1, "\n", 1);
	return (0);
}
