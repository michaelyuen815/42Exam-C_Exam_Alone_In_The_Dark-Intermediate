/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:29:20 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/09 23:11:45 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORD_ALPHLONG_H
# define ORD_ALPHLONG_H

# define BL_LW(ch) (ch > 96 && ch < 123)

char *ft_strchr(char *str, int c);
int ft_strlen(char *str);
int ft_strncmp(char *str1, char *str2, int n);

typedef struct s_string	t_string;
typedef	struct s_list	t_list;

struct		s_list
{
	int		len;
	t_string *str;
	t_list	*next;
};

struct		s_string
{
	char*	str;
	t_string *next;
};

#endif
