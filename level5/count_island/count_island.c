/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 11:00:46 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 11:48:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFF_SIZE 100000

int ft_row(const char *src)
{
	char *pt;

	pt = (char*)src;
	while (*pt != '\n' && *pt)
		pt++;
	return ((int)(pt - src + 1));
}

void ft_fill(char *src, int size, int row, int i, char ch)
{
	if (i < 0 || i > size || i % row == row - 1)
		return ;
	if (src[i] != 'X')
		return ;
	src[i] = ch;
	ft_fill(src, size, row, i + 1, ch);
	ft_fill(src, size, row, i - 1, ch);
	ft_fill(src, size, row, i + row, ch);
	ft_fill(src, size, row, i - row, ch);
}

void count_island(char *src, int size)
{
	int i;
	int row;
	char ch;

	row = ft_row(src);
	i = -1;
	ch = '0';
	while (src[++i])
	{
		if ((i % row != row - 1 && src[i] != '.' && src[i] != 'X') || (i % row == row - 1 && src[i] != '\n'))
		{
			write(1, "\n", 1);
			return ;
		}
	}
	i = -1;
	while (src[++i])
		if (src[i] == 'X')
			ft_fill(src, size, row, i, ch++);
	write(1, src, size);
}

int main(int ac, char **av)
{
	int fd;
	int rd;
	char buff[BUFF_SIZE];

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 0)
		{
			rd = read(fd, buff, BUFF_SIZE);
			if (rd > 0)
			{
				buff[rd] = 0;
				count_island(buff, rd);
			}
			else
				write(1, "\n", 1);
			close(fd);
		}
		else
			write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}
