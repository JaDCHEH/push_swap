/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:10:35 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:33:23 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_stack	*a)
{
	t_strct	*ac;
	int		min;

	ac = a->top;
	min = a->top->data;
	while (ac)
	{
		if (ac->data < min)
			min = ac->data;
		ac = ac->next;
	}
	return (min);
}

int	min_index(t_stack *s, int min)
{
	int		index;
	t_strct	*tmp;

	tmp = s->top;
	index = 0;
	while (tmp && tmp->data != min)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}

void	push_min(t_stack *a, int index, int i)
{
	if (index > i / 2)
	{
		while (index < i)
		{
			rra(a);
			index++;
		}
	}
	if (index <= i / 2)
	{
		while (index > 0)
		{
			ra(a);
			index--;
		}
	}
}

void	medium_sort(t_stack *a, t_stack *b, int i)
{
	int	min;
	int	index;

	while (a->top)
	{
		min = find_min(a);
		index = min_index(a, min);
		push_min(a, index, i);
		pb(a, b);
		if (!a->top->next->next->next)
		{
			sort_3(a);
			break ;
		}
		i--;
	}
	while (b->top)
		pa(a, b);
}
