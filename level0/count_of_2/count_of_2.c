/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:58:16 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/09 13:04:55 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int count_of_2inv(int n)
{
	int ret;

	ret = 0;
	while (n)
	{
		ret += (n % 10 == 2 ? 1 : 0);
		n /= 10;
	}
	return (ret);
}

int	count_of_2(int n)
{
	int i;
	int ret;

	ret = 0;
	if (n <= 1)
		return (0);
	i = 1;
	while (++i <= n)
		ret += count_of_2inv(i);
	return (ret);
}