/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:29:13 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/10 12:38:27 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	int i;
	int ret;
	int tmp;

	if (!root)
		return (-1);
	i = -1;
	ret = 0;
	while (root->nodes[++i])
	{
		tmp = height_tree(root->nodes[i]) + 1;
		if (tmp > ret)
			ret = tmp;
	}
	return (ret);
}
