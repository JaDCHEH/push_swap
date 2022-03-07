/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:25:08 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:34:17 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *a, t_stack*b)
{
	pushtop(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack*b)
{
	pushtop(a, b);
	ft_printf("pb\n");
}

void	ra(t_stack *s)
{
	rotate(s);
	ft_printf("ra\n");
}

void	rb(t_stack *s)
{
	rotate(s);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
