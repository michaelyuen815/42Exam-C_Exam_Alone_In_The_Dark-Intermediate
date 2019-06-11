/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 20:32:35 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 21:04:05 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

typedef struct  s_point
{
	  int           x;
	  int           y;
}               t_point;

void  flood_fill(char **tab, t_point size, t_point begin);

#endif
