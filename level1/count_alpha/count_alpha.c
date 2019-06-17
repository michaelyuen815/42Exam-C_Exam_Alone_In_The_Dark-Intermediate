/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 13:59:39 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/16 14:18:45 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define BL_AP(ch) ((ch >= 97 && ch <= 122) || BL_UP(ch)) 
#define BL_UP(ch) (ch >= 65 && ch <= 90)

int main(int ac, char **av)
{
	int tmp[255];
	int i;
	char pt;
	char print;

	if (ac == 2)
	{
		i = 96;
		while (++i < 123)
			tmp[i] = 0;
		i = -1;
		while (av[1][++i])
			if (BL_AP(av[1][i]))
				tmp[(int)(av[1][i] + (BL_UP(av[1][i]) ? 32 : 0))]++;
		i = -1;
		while (av[1][++i])
		{
			pt = av[1][i] + (BL_UP(av[1][i]) ? 32 : 0);
			if (BL_AP(av[1][i]) && tmp[(int)pt])
			{
				if (print)
					printf(", ");
				printf("%d%c", tmp[(int)pt], pt);
				tmp[(int)pt] = 0;
				print = 1;
			}
		}
	}
	printf("\n");
	return (0);
}
