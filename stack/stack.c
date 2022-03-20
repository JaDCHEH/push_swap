/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:29:18 by cjad              #+#    #+#             */
/*   Updated: 2022/03/17 15:06:20 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
}

void	addfront(t_stack *s, int data)
{
	t_strct	*new;

	new = malloc (sizeof(t_strct));
	if (!new)
		exit(1);
	new->data = data;
	new->next = s->top;
	s->top = new;
}

void	print_stack(t_stack *s)
{
	t_strct	*tr;

	tr = s->top;
	while (tr)
	{
		ft_printf("%d\n", tr->data);
		tr = tr->next;
	}
}

void	check_av(t_stack *a)
{
	t_strct	*tmp1;
	t_strct	*tmp2;

	tmp1 = a->top;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
			{
				ft_printf("Error\n");
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	is_sorted(t_stack *a)
{
	t_strct	*tmp1;
	t_strct	*tmp2;

	tmp1 = a->top;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->data > tmp2->data)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}
