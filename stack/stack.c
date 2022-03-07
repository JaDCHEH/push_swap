/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:29:18 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 18:45:14 by cjad             ###   ########.fr       */
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

void	check_av(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}