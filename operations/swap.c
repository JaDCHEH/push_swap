/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:25:18 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:34:34 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack	*s)
{
	swap(s);
	ft_printf("sa\n");
}

void	sb(t_stack	*s)
{
	swap(s);
	ft_printf("sb\n");
}

void	ss(t_stack	*s1, t_stack	*s2)
{
	swap(s1);
	swap(s2);
	ft_printf("ss\n");
}
