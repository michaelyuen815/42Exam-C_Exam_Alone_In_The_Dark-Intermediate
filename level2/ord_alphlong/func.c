/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:37:27 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/09 23:12:19 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ord_alphlong.h"

int ft_strncmp(char *str1, char *str2, int n)
{
	char ch_s1;
	char ch_s2;

	while (*str1 && *str2 && n--)
	{
		ch_s1 = *str1 - (BL_LW(*str1) ? 32 : 0);
		ch_s2 = *str2 - (BL_LW(*str2) ? 32 : 0);
		if (ch_s1 != ch_s2)
			return (ch_s1 - ch_s2);
		str1++;
		str2++;
	}
	return (0);
}

char *ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

int ft_strlen(char *str)
{
	int ret;

	ret = 0;
	while (*str++)
		ret++;
	return (ret);
}
