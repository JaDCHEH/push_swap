/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:29:47 by cjad              #+#    #+#             */
/*   Updated: 2022/03/07 18:44:25 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_strct{
	int				data;
	struct s_strct	*next;
}	t_strct;

typedef struct s_stack{
	t_strct	*top;
}	t_stack;

typedef struct s_complex
{
	t_strct	*ac;
	int		first;
	int		last;
	int		flag;
	int		flag1;
	int		flag2;
	int		flag3;
	int		index;
	int		x;
	int		i;
}	t_complex;

void	ft_printf(const char *s, ...);
int		ft_atoi(char	*str);
void	check_av(char **av);
void	addfront(t_stack *s, int data);
void	stack_init(t_stack *s);
void	print_stack(t_stack *s);
void	swap(t_stack *t_stack);
void	pushtop(t_stack	*t_stack_1, t_stack	*t_stack_2);
void	rotate(t_stack *t_stack);
void	rev_rotate(t_stack *t_stack);
void	sb(t_stack *s);
void	sa(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rrr(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sort_3(t_stack *s);
void	simple_sort(t_stack *s, int i);
void	medium_sort(t_stack *a, t_stack *b, int i);
void	complex_sort(t_stack	*a, t_stack *b, int s, int nchunk);
void	complex_sort_1(t_stack *a, t_stack *b, int i);
void	index_stack(t_stack *a, int size);
char	*ft_strjoin(char	*s1, char *s2);
char	*get_next_line(int fd);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strdup(const char	*s1);
int		ft_strcmp(char	*str1, char	*str2);
void	apply_operation(char	*str, t_stack *a, t_stack *b);

#endif
