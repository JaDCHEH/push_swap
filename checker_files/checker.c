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

int	main(int ac, char	**av)
{
	t_stack	a;
	t_stack	b;
	int		i;

	i = ac - 1;
	check_av(av);
	stack_init(&a);
	stack_init(&b);
	while (i > 0)
	{
		addfront(&a, ft_atoi(av[i]));
		i--;
	}
	operations(&a, &b);
	if (is_sorted(&a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}
