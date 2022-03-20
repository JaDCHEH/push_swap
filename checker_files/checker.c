/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:22:40 by cjad              #+#    #+#             */
/*   Updated: 2022/03/17 15:24:59 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char	*str1, char	*str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	check_operations(char	*str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "sa\n") && ft_strcmp(str, "sb\n")
		&& ft_strcmp(str, "ra\n") && ft_strcmp(str, "rb\n")
		&& ft_strcmp(str, "rra\n") && ft_strcmp(str, "rrb\n")
		&& ft_strcmp(str, "rr\n") && ft_strcmp(str, "rrr\n")
		&& ft_strcmp(str, "ss\n") && ft_strcmp(str, "pa\n")
		&& ft_strcmp(str, "pb\n"))
	{
		free(str);
		ft_printf("Error\n");
		exit(1);
	}
	apply_operation(str, a, b);
}

void	operations(t_stack *a, t_stack *b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		check_operations(str, a, b);
		free(str);
		str = get_next_line(0);
	}
	free(str);
}

int	main(int ac, char	**av)
{
	t_stack	a;
	t_stack	b;
	int		i;

	i = ac - 1;
	stack_init(&a);
	stack_init(&b);
	while (i > 0)
	{
		parsing(av[i], &a);
		i--;
	}
	check_av(&a);
	operations(&a, &b);
	if (is_sorted(&a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
