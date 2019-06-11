/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:11:53 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 10:35:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int count_size(struct s_node *n)
{
	int ret;

	if (!n)
		return (0);
	ret = 1;
	ret += count_size(n->left);
	ret += count_size(n->right);
	return (ret);
}

int can_split_main(int prefix, struct s_node *n)
{
	int i_left;
	int i_right;

	i_left = count_size(n->left);
	i_right = count_size(n->right);
	if (i_left == 1 + prefix + i_right)
		return (1);
	if (i_right == 1 + prefix + i_left)
		return (1);
	if (i_right < 1 + prefix + i_left && i_left < 1 + prefix + i_right)
		return (0);
	if (i_left > 1 + prefix + i_right)
		return (can_split_main(1 + prefix + i_right, n->left));
	if (i_right > 1 + prefix + i_left)
		return (can_split_main(1 + prefix + i_left, n->right));
	else
		return (can_split_main(1 + prefix + i_right, n->left) || can_split_main(1 + prefix + i_left, n->right));
}

int	can_split(struct s_node *n)
{
	if (!n)
		return (0);
	return (can_split_main(0, n));
}
