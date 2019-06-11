/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:30:32 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 15:18:00 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int ft_factorial(int n)
{
	int i;
	int ret;

	i = 1;
	ret = 1;

	while (++i <= n)
		ret *= i;
	return (ret);
}

int ft_fill(int **ret, int *tmp, int *cur, int n, int cur_i)
{
	int i;
	int j;
	char chk;

	i = -1;
	while (++i < n)
	{
		j = -1;
		chk = 0;
		while (++j < cur_i)
			chk |= (tmp[j] == i);
		if (!chk)
		{
			tmp[cur_i] = i;
			if (cur_i == n - 1)
			{
				j = -1;
				while (++j < n)
					ret[*cur][j] = tmp[j];
				(*cur)++;
			}
			else
				ft_fill(ret, tmp, cur, n, cur_i + 1);
		}
	}
	return (1);
}

int **range_comb(int n)
{
	int i;
	int len;
	int **ret;
	int tmp[2048];
	int cur;

	if (n <= 0)
		return (NULL);
	cur = 0;
	len = ft_factorial(n);
	ret = malloc(sizeof(int*) * (len + 1));
	ret[len] = 0;
	i = -1;
	while (++i < len)
	{
		ret[i] = malloc(sizeof(int) * n);
		ret[i][n] = 0;
	}
	ft_fill(ret, tmp, &cur, n, 0); 
	return (ret);
}
