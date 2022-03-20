/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:25:00 by cjad              #+#    #+#             */
/*   Updated: 2022/03/08 13:20:31 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
}

void	pushtop(t_stack *stack_1, t_stack *stack_2)
{
	t_strct	*tmp;
	t_strct	*tmp2;

	if (stack_1->top == NULL)
		return ;
	tmp = stack_1->top;
	tmp2 = stack_2->top;
	stack_1->top = stack_1->top->next;
	stack_2->top = tmp;
	stack_2->top->next = tmp2;
}

void	rotate(t_stack *stack)
{
	t_strct	*temp;
	int		data;

	temp = stack->top;
	if (temp)
	{
		while (temp->next != NULL)
		{
			data = temp->data;
			temp->data = temp->next->data;
			temp->next->data = data;
			temp = temp->next;
		}
	}
}

void	rev_rotate(t_stack *stack)
{
	t_strct	*temp;
	t_strct	*last;

	temp = stack->top;
	if (temp == NULL || temp->next == NULL)
		return ;
	while (temp->next != NULL)
	{
		if (temp->next->next == NULL)
			last = temp;
		temp = temp->next;
	}
	temp->next = stack->top;
	stack->top = temp;
	last->next = NULL;
}
