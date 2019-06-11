/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:19:43 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 15:37:08 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	volume_histogram(int *histogram, int size)
{
	int i;
	int j;
	int left_h;
	int right_h;
	int ret;

	ret = 0;
	left_h = 0;
	right_h = 0;
	i = -1;
	while (++i < size)
	{
		if (histogram[i] < left_h && histogram[i] < right_h)
			ret += ((left_h > right_h ? right_h : left_h) - histogram[i]);
		if (histogram[i] > left_h || histogram[i] == right_h)
		{
			left_h = histogram[i];
			right_h = 0;
			j = i;
			while (++j < size)
				right_h = (histogram[j] > right_h ? histogram[j] : right_h);
		}
	}
	return (ret);
}
