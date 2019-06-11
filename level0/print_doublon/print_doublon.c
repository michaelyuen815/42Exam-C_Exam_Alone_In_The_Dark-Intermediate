/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:31:34 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/09 21:44:52 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void print_doublon(int *a, int na, int *b, int nb)
{
	char bl_pt;

	bl_pt = 0;
	while (na && nb)
	{
		if (*a == *b)
		{
			if (bl_pt)
				printf(" ");
			bl_pt = 1;
			printf("%d", *a);
			na--;
			nb--;
			a++;
			b++;
		}
		else if (*a > *b)
		{
			b++;
			nb--;
		}
		else
		{
			a++;
			na--;
		}
	}
	printf("\n");
}
