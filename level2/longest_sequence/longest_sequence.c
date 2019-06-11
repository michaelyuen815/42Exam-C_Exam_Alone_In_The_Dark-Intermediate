/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:32:59 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 10:10:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int lg_seq_cur(int *ret, struct s_node *node)
{
	int cur;
	int cur_l;
	int cur_r;

	if (!node)
		return (0);
	cur = 1;
	cur_r = lg_seq_cur(ret, node->right);
	cur_l = lg_seq_cur(ret, node->left);
	if (node->left)
		if (node->left->value != node->value + 1)
			cur_l = 0;
	if (node->right)
		if (node->right->value != node->value + 1)
			cur_r = 0;
	cur += (cur_l > cur_r ? cur_l : cur_r);
	*ret = (*ret > cur ? *ret : cur);
	return (cur);
}

int	longest_sequence(struct s_node *node)
{
	int ret;

	if (!node)
		return (0);
	ret = 0;
	lg_seq_cur(&ret, node);
	return (ret);
}
