/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyuen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 21:46:14 by chyuen            #+#    #+#             */
/*   Updated: 2019/06/09 22:24:53 by chyuen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void)
{
	struct s_queue *ret;

	if (!(ret = malloc(sizeof(struct s_queue))))
		return (NULL);
	ret->first = NULL;
	ret->last = NULL;

	return (ret);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *target;

	if (!(target = malloc(sizeof(struct s_node))))
		return ;
	target->content = content;
	target->next = NULL;
	if (!queue->first)
		queue->first = target;
	if (queue->last)
		queue->last->next = target;
	queue->last = target;
}

void *dequeue(struct s_queue *queue)
{
	struct s_node *node;
	void *content;

	if (!queue)
		return (NULL);
	if (!queue->first)
		return (NULL);
	node = queue->first;
	content = node->content;
	queue->first = node->next;
	free(node);
	if (!queue->first)
		queue->last = NULL;
	return (content);
}

void *peek(struct s_queue *queue)
{
	if (!queue)
		return (NULL);
	if (!queue->first)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue)
		return (1);
	if (!queue->first)
		return (1);
	return (0);
}
