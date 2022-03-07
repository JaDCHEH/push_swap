/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:10:26 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:32:32 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max(t_stack	*a)
{
	t_strct	*ac;
	int		max;

	ac = a->top;
	max = a->top->data;
	while (ac)
	{
		if (ac->data > max)
			max = ac->data;
		ac = ac->next;
	}
	return (max);
}

int	max_index(t_stack *s, int max)
{
	int		index;
	t_strct	*tmp;

	tmp = s->top;
	index = 0;
	while (tmp && tmp->data != max)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

void	push_max(t_stack *b, int index, int i)
{
	if (index > i / 2)
	{
		while (index < i)
		{
			rrb(b);
			index++;
		}
	}
	if (index <= i / 2)
	{
		while (index > 0)
		{
			rb(b);
			index--;
		}
	}
}

void	complex_sort_1(t_stack *a, t_stack *b, int i)
{
	int	max;
	int	index;

	while (b->top)
	{
		max = find_max(b);
		index = max_index(b, max);
		push_max(b, index, i);
		pa(a, b);
		i--;
	}
}
