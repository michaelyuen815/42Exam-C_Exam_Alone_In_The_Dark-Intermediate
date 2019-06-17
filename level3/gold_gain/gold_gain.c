/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:31:41 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/16 15:52:23 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	gold_gain(int **mine, int n)
{
	int i;
	int j;
	int cal;
	int ret;
	int **tmp;

	tmp = malloc(sizeof(int*) * n);
	i = -1;
	while (++i < n)
	{
		tmp[i] = (int *)malloc(sizeof(int) * n);
		tmp[i][0] = mine[i][0];
	}
	
	ret = 0;
	j = 0;
	while (++j < n)
	{
		i = -1;
		while (++i < n)
		{
			cal = 0;
			if (i > 0)
				cal = tmp[i - 1][j - 1];
			if (tmp[i][j - 1] > cal)
				cal = tmp[i][j - 1];
			if (i < n - 1)
				if (tmp[i + 1][j - 1] > cal)
					cal = tmp[i + 1][j - 1];
			tmp[i][j] = cal + mine[i][j];
			if (j == n - 1 && tmp[i][j] > ret)
				ret = tmp[i][j];
		}
	}
	return (ret);
}
