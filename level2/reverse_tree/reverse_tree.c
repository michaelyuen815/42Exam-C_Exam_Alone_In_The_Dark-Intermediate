/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:49:26 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/09 23:53:17 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	struct s_node *tmp;

	if (!root)
		return ;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}
