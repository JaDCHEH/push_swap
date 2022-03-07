/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:29:13 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 15:34:49 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_array(t_stack *a, int *tab)
{
	t_strct	*tmp;
	int		j;

	j = 0;
	tmp = a->top;
	while (tmp)
	{
		tab[j] = tmp->data;
		j++;
		tmp = tmp->next;
	}
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_array(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

void	refill_stack(t_stack *a, int	*tab, int size)
{
	int		i;
	t_strct	*tmp;

	tmp = a->top;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->data == tab[i])
			{
				tmp->data = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	index_stack(t_stack *a, int size)
{
	int	*tab;

	tab = (int *) malloc (sizeof(int) * size);
	if (!tab)
		exit(1);
	fill_array(a, tab);
	sort_array(tab, size);
	refill_stack(a, tab, size);
	free(tab);
}
