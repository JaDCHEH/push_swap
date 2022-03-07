/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:25:00 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:34:06 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->top->next == NULL || stack->top == NULL)
	{
		ft_printf("Only one or no element, cannot swap.\n");
		return ;
	}
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
}

void	pushtop(t_stack *stack_1, t_stack *stack_2)
{
	t_strct	*tmp;
	t_strct	*tmp2;

	if (stack_1->top == NULL)
	{
		ft_printf("Stack Underflow!\n");
		return ;
	}
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
	while (temp->next != NULL)
	{
		data = temp->data;
		temp->data = temp->next->data;
		temp->next->data = data;
		temp = temp->next;
	}
}

void	rev_rotate(t_stack *stack)
{
	t_strct	*temp;
	t_strct	*last;

	temp = stack->top;
	if (temp == NULL || temp->next == NULL)
	{
		ft_printf("Only one element, cannot reverse.\n");
		return ;
	}
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
