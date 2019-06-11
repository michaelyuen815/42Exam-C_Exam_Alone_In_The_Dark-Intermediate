/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:31:24 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 21:03:46 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char ch;

	ch = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';

	if (begin.x - 1 >= 0)
		if (tab[begin.y][begin.x - 1] == ch)
			flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	if (begin.y - 1 >= 0)
		if (tab[begin.y - 1][begin.x] == ch)
			flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	if (begin.x + 1 < size.x)
		if (tab[begin.y][begin.x + 1] == ch)
			flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
	if (begin.y + 1 < size.y)
		if (tab[begin.y + 1][begin.x] == ch)
			flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
}
