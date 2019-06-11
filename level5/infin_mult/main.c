/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:15:55 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 19:16:18 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int ret;

	ret = 0;
	while (*str++)
		ret++;
	return (ret);
}

char *ft_cal(char *cal, char *s1, char *s2, int *len)
{
	int i_s1;
	int i_s2;
	int len_s1;
	int len_s2;
	int tmp;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);

	i_s1 = -1;
	while (++i_s1 < len_s1 + len_s2)
		cal[i_s1] = '0';
	i_s1 = -1;
	while (++i_s1 < len_s1)
	{
		i_s2 = -1;
		while (++i_s2 < len_s2)
		{
			tmp = (s1[len_s1 - 1 - i_s1] - '0') * (s2[len_s2 - 1 - i_s2] - '0') + cal[i_s1 + i_s2] - '0';
			cal[i_s1 + i_s2] = tmp % 10 + '0';
			cal[i_s1 + i_s2 + 1] = (cal[i_s1 + i_s2 + 1] - '0' + tmp / 10) + '0';
		}
	}
	*len = len_s1 + len_s2 - (cal[len_s1 + len_s2 -1] == '0' ? 1 : 0);
	return (cal);
}

int main(int ac, char **av)
{
	char cal[4096];
	int i;
	int len;

	if (ac == 3)
	{
		if (*av[1] == '0' || *av[2] == '0')
			write(1, "0", 1);
		else
		{
			if ((*av[1] == '-' || *av[2] == '-') && !(*av[1] == '-' && *av[2] == '-'))
				write(1, "-", 1);
			av[1] += (*av[1] == '-' ? 1 : 0);
			av[2] += (*av[2] == '-' ? 1 : 0);
			len = 0;
			ft_cal(cal, av[1], av[2], &len);
			i = -1;
			while (++i < len)
				write(1, &cal[len - 1 - i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}