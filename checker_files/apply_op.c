/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:22:31 by cjad              #+#    #+#             */
/*   Updated: 2022/03/08 13:22:32 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_op_2(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(str, "ss\n"))
	{
		swap(a);
		swap(b);
	}
	if (!ft_strcmp(str, "rr\n"))
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strcmp(str, "rrr\n"))
	{
		rev_rotate(a);
		rev_rotate(b);
	}
}

void	apply_operation(char	*str, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(str, "sa\n"))
		swap(a);
	if (!ft_strcmp(str, "sb\n"))
		swap(b);
	if (!ft_strcmp(str, "ra\n"))
		rotate(a);
	if (!ft_strcmp(str, "rb\n"))
		rotate(b);
	if (!ft_strcmp(str, "rra\n"))
		rev_rotate(a);
	if (!ft_strcmp(str, "rrb\n"))
		rev_rotate(b);
	if (!ft_strcmp(str, "pa\n"))
		pushtop(b, a);
	if (!ft_strcmp(str, "pb\n"))
		pushtop(a, b);
	apply_op_2(str, a, b);
}
