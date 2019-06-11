/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:09:05 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 09:31:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack *ret;

	if (!(ret = malloc(sizeof(struct s_stack))))
		return (NULL);
	ret->top = NULL;
	return (ret);
}

void *pop(struct s_stack *stack)
{
	struct s_node *cur;
	void *content;

	if (!stack)
		return (NULL);
	if (!stack->top)
		return (NULL);
	cur = stack->top;
	content = cur->content;
	stack->top = cur->next;
	free(cur);
	return (content);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *cur;

	if (!stack)
		return ;
	if (!(cur = malloc(sizeof(struct s_node))))
		return ;
	cur->content = content;
	cur->next = stack->top;
	stack->top = cur;
}

void *peek(struct s_stack *stack)
{
	if (!stack)
		return (NULL);
	if (!stack->top)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!stack)
		return (1);
	if (!stack->top)
		return (1);
	return (0);
}
