/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:10:18 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:35:53 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swaped(t_stack *a, t_stack *b, t_complex *cmp, int *s)
{
	if (cmp->first > *s - cmp->last)
	{
		while (cmp->last < *s)
		{
			rra(a);
			cmp->last++;
		}
		pb(a, b);
	}
	else
	{
		while (cmp->first > 0)
		{
			ra(a);
			cmp->first--;
		}
		pb(a, b);
	}
	(*s)--;
	return (1);
}

int	least_swp(t_stack *a, t_stack *b, int first, int *s)
{
	if (first > *s / 2)
	{
		while (first < *s)
		{
			rra(a);
			first++;
		}
	}
	if (first <= *s / 2)
	{
		while (first > 0)
		{
			ra(a);
			first--;
		}
	}
	pb(a, b);
	(*s)--;
	return (0);
}

int	move_chunk(t_stack *a, t_stack *b, int *s, t_complex *cmp)
{
	cmp->ac = a->top;
	cmp->flag = 0;
	cmp->index = 0;
	cmp->first = -1;
	while (cmp->ac)
	{
		if ((cmp->ac->data >= cmp->x
				&& cmp->ac->data <= (cmp->x + cmp->i - 1)) && cmp->flag == 0)
		{
			cmp->first = cmp->index;
			cmp->flag = 1;
		}
		if (cmp->ac->data >= cmp->x && cmp->ac->data <= (cmp->x + cmp->i - 1))
		{
			cmp->last = cmp->index;
		}
		cmp->index++;
		cmp->ac = cmp->ac->next;
	}
	if (cmp->first == -1)
		return (0);
	else if (cmp->first != cmp->last)
		return (swaped(a, b, cmp, s));
	else
		return (least_swp(a, b, cmp->first, s));
}

void	chunker(int s, t_complex *cmp, int *nchunk)
{
	if (s < 250 && cmp->flag1 == 0)
	{
		*nchunk = 8;
		cmp->x = 0;
		cmp->flag1 = 1;
		cmp->i = s / *nchunk;
	}
	if (s <= 150 && cmp->flag2 == 0)
	{
		*nchunk = 5;
		cmp->x = 0;
		cmp->flag2 = 1;
		cmp->i = s / *nchunk;
	}
	if (s <= 50 && cmp->flag3 == 0)
	{
		*nchunk = 3;
		cmp->x = 0;
		cmp->flag3 = 1;
		cmp->i = s / *nchunk;
	}
}

void	complex_sort(t_stack	*a, t_stack *b, int s, int nchunk)
{
	t_complex	cmp;
	int			i;

	cmp.x = 0;
	cmp.flag1 = 0;
	cmp.flag2 = 0;
	cmp.flag3 = 0;
	i = s;
	cmp.i = s / nchunk;
	while (a->top)
	{
		if (!move_chunk(a, b, &s, &cmp))
			cmp.x = cmp.x + cmp.i;
		chunker(s, &cmp, &nchunk);
	}
	complex_sort_1(a, b, i);
}
