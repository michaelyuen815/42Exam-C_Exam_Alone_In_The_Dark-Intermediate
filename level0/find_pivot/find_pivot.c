/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:02:14 by exam              #+#    #+#             */
/*   Updated: 2019/06/18 09:09:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int find_pivot(int *arr, int n)
{
	int left;
	int right;
	int i;

	left = 0;
	right = 0;
	i = -1;
	while (++i < n)
		right += arr[i];
	i = -1;
	while (++i < n)
	{
		if (i > 0)
			left += arr[i - 1];
		right -= arr[i];
		if (left == right)
			return (i);
	}
	return (-1);
}
