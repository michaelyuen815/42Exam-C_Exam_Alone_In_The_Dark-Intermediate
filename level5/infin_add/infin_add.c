/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:16:07 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/17 15:27:42 by chyuen           ###   ########.fr       */
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

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int ft_cal(char **ret, char *s1, char *s2, char sign)
{
	int len;
	int len_s1;
	int len_s2;
	int i;
	char tmp;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len = (len_s2 > len_s1 ? len_s2 : len_s1) + 1;
	*ret = malloc(sizeof(char) * (len + 1));
	(*ret)[len] = 0;
	i = -1;
	while (++i < len)
		(*ret)[i] = '0';
	i = -1;
	while (++i < len)
	{
		tmp = (len_s1 - 1 - i) >= 0 ? s1[len_s1 - 1 - i] - '0' : 0;
		if (sign)
			tmp += (len_s2 - 1 - i) >= 0 ? s2[len_s2 - 1 - i] - '0' : 0;
		else
			tmp -= (len_s2 - 1 - i) >= 0 ? s2[len_s2 - 1 - i] - '0' : 0;
		(*ret)[len - 1 - i] += tmp;
		if ((*ret)[len - 1 - i] > 57)
		{
			(*ret)[len - 1 - i] -= 10;
			(*ret)[len - 2 - i]++;
		}
		else if ((*ret)[len - 1 - i] < 48)
		{
			(*ret)[len - 1 - i] += 10;
			(*ret)[len - 2 - i]--;		
		}
	}
	while (**ret == '0' && *(*ret + 1))
	{
		(*ret)++;
		len--;
	}
	return (len);
}

int main(int ac, char **av)
{
	int len;
	int len_s1;
	int len_s2;
	char *ret;

	if (ac == 3)
	{
		ret = NULL;
		if (*av[1] == '0' || *av[2] == '0')
		{
			ret = *av[1] == '0' ? av[2] : av[1];
			len = *av[1] == '0' ? ft_strlen(av[2]) : ft_strlen(av[1]);
		}
		if ((*av[1] == '-' && *av[2] == '-') || (*av[1] != '-' && *av[2] != '-'))
		{
			if (*av[1] == '-')
			{
				av[1]++;
				av[2]++;
				write(1, "-", 1);
			}
			len = ft_cal(&ret, av[1], av[2], 1);
		}
		else
		{
			len_s1 = ft_strlen(av[1]) - (*av[1] == '-');
			len_s2 = ft_strlen(av[2]) - (*av[1] == '-');
			if (len_s1 == len_s2 && !ft_strcmp(av[1] + (*av[1] == '-'), av[2] + (*av[2] == '-')))
			{
				len = 1;
				ret = malloc(sizeof(char) * 2);
				ret[0] = '0';
			}
			else if (len_s1 > len_s2 || (len_s1 == len_s2 && ft_strcmp(av[1] + (*av[1] == '-'), av[2] + (*av[2] == '-')) > 0))
			{
				if (*av[1] == '-')
					write(1, "-", 1);
				len = ft_cal(&ret, av[1] + (*av[1] == '-'), av[2] + (*av[2] == '-'), 0);
			}
			else 
			{
				if (*av[2] == '-')
					write(1, "-", 1);
				len = ft_cal(&ret, av[2] + (*av[2] == '-'), av[1] + (*av[1] == '-'), 0);
			}
		}
		write(1, ret, len);
	}
	write(1, "\n", 1);
	return (0);
}
