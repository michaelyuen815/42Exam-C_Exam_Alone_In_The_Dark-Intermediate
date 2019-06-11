/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:34:51 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 22:54:33 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *ret;
	struct s_node *cur;

	if (!bst)
		return (NULL);
	ret = convert_bst(bst->left);
	if (ret)
	{
		cur = ret;
		while (cur->right)
			cur = cur->right;
		cur->right = bst;
		bst->left = cur;
	}
	else
		ret = bst;
	cur = bst;
	cur->right = convert_bst(bst->right);
	if (cur->right)
		cur->right->left = cur;
	return (ret);
}
