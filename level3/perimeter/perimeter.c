/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:55:07 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 23:11:13 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void print_root(struct s_node *root)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
		printf(" %d", root->value);
	else
	{
		print_root(root->left);
		print_root(root->right);
	}
}

void print_left(struct s_node *root)
{
	if (!root)
		return ;
	printf(" %d", root->value);
	print_left(root->left);
	print_root(root->right);
}

void print_right(struct s_node *root)
{
	if (!root)
		return ;
	print_root(root->left);
	print_right(root->right);
	printf(" %d", root->value);
}

void perimeter(struct s_node *root)
{
	if (!root)
		return ;
	printf("%d", root->value);
	print_left(root->left);
	print_right(root->right);
	printf("\n");
}
