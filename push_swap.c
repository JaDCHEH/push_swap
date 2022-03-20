/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:29:43 by cjad              #+#    #+#             */
/*   Updated: 2022/03/17 15:03:20 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	sort(int s, t_stack *a, t_stack *b)
{
	if (s <= 3 && s != 1)
		simple_sort(a, s);
	else if (s > 3 && s < 50)
		medium_sort(a, b, s);
	else if (s >= 50 && s < 300)
		complex_sort(a, b, s, 5);
	else if (s >= 300)
		complex_sort(a, b, s, 12);
}

int	main(int ac, char	**av)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		s;

	i = ac - 1;
	stack_init(&a);
	stack_init(&b);
	while (i > 0)
	{
		parsing(av[i], &a);
		i--;
	}
	check_av(&a);
	s = list_len(&a);
	index_stack(&a, s);
	if (is_sorted(&a))
		sort(s, &a, &b);
}
