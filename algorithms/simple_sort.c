/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:10:41 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:33:34 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack *s)
{
	if (s->top->data > s->top->next->data
		&& s->top->next->data < s->top->next->next->data
		&& s->top->data < s->top->next->next->data)
		sa(s);
	else if (s->top->data > s->top->next->data
		&& s->top->next->data > s->top->next->next->data)
	{
		sa(s);
		rra(s);
	}
	else if (s->top->data > s->top->next->data
		&& s->top->next->data < s->top->next->next->data
		&& s->top->data > s->top->next->next->data)
		ra(s);
	else if (s->top->data < s->top->next->data
		&& s->top->next->data > s->top->next->next->data
		&& s->top->data < s->top->next->next->data)
	{
		sa(s);
		ra(s);
	}
	else if (s->top->data < s->top->next->data
		&& s->top->next->data > s->top->next->next->data
		&& s->top->data > s->top->next->next->data)
		rra(s);
}

void	sort_2(t_stack *s)
{
	if (s->top->data > s->top->next->data)
		sa(s);
}

void	simple_sort(t_stack *s, int i)
{
	if (i == 2)
		sort_2(s);
	else
		sort_3(s);
}
