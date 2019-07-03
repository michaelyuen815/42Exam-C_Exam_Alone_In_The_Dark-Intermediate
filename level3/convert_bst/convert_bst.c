/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 15:54:11 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/16 16:04:24 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *ret;

	if (!bst)
		return (NULL);
	ret = convert_bst(bst->left);
	bst->right = convert_bst(bst->right);
	if (ret)
	{
		ret->left->right = bst;
		bst->left = ret->left;
	}
	else
		ret = bst;
	if (bst->right)
	{
		bst->right->left->right = ret;
		ret->left = bst->right->left;
		bst->right->left = bst;
	}
	else
	{
		bst->right = ret;
		ret->left = bst;
	}
	return (ret);
}
