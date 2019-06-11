/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:55:07 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 00:18:38 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int max_tree(struct s_node *n)
{
	int ret_left;
	int ret_right;

	if (!n)
		return (0);
	ret_left = max_tree(n->left);
	ret_right = max_tree(n->right);
	return (1 + (ret_left > ret_right ? ret_left : ret_right));
}

int	width_tree(struct s_node *n)
{
	int	ret_left;
	int ret_right;
	int ret_cur;
	int ret_next;

	if (!n)
		return (0);
	ret_left = max_tree(n->left);
	ret_right = max_tree(n->right);
	ret_cur = ret_left + ret_right + 1;
	if (ret_left == ret_right)
		return (ret_cur);
	else if (ret_left > ret_right)
		ret_next = width_tree(n->left);
	else
		ret_next = width_tree(n->right);
	return (ret_next > ret_cur ? ret_next : ret_cur);
}
