/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:25:13 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:34:24 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *s)
{
	rev_rotate(s);
	ft_printf("rra\n");
}

void	rrb(t_stack *s)
{
	rev_rotate(s);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
