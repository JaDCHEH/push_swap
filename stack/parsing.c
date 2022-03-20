/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:06:50 by cjad              #+#    #+#             */
/*   Updated: 2022/03/17 15:06:51 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_len(t_stack *a)
{
	t_strct	*tmp;
	int		i;

	tmp = a->top;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	parsing(char *s, t_stack *a)
{
	char	**str;
	int		i;
	int		j;

	str = ft_split(s, ' ');
	i = 0;
	while (str[i])
		i++;
	i = i - 1;
	j = i;
	while (i >= 0)
	{
		addfront(a, ft_atoi(str[i]));
		i--;
	}
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}
