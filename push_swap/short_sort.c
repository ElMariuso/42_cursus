/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:13:31 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 13:59:47 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*lowest_value(t_stack *stack)
{
	t_stack	*to_return;

	to_return = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < to_return->value)
			to_return = stack;
		stack = stack->next;
	}
	return (to_return);
}

void	three_sort(t_stack **stack_a, t_stack **stack_b)
{
	while (is_sorted(*stack_a) != true)
	{
		if ((*stack_a)->value < (*stack_a)->next->value
			&& (*stack_a)->value > (*stack_a)->next->next->value)
			ft_rra_rrb_rrr(*stack_a, *stack_b, 'a');
		else if ((*stack_a)->value > (*stack_a)->next->value
			&& (*stack_a)->value > (*stack_a)->next->next->value)
			ft_ra_rb_rr(*stack_a, *stack_b, 'a');
		if (is_sorted(*stack_a) != true)
		{
			if ((*stack_a)->value > (*stack_a)->next->value
				&& (*stack_a)->value < (*stack_a)->next->next->value)
				ft_sa_sb_ss(*stack_a, *stack_b, 'a');
			else if ((*stack_a)->value < (*stack_a)->next->value
				&& (*stack_a)->value < (*stack_a)->next->next->value)
				ft_sa_sb_ss(*stack_a, *stack_b, 'a');
		}
	}
}

void	five_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (lowest_value(*stack_a)->index == 3)
	{
		ft_rra_rrb_rrr(*stack_a, *stack_b, 'a');
		ft_rra_rrb_rrr(*stack_a, *stack_b, 'a');
		ft_pa_pb(stack_a, stack_b, 'b');
	}
	else
	{
		ft_rra_rrb_rrr(*stack_a, *stack_b, 'a');
		ft_pa_pb(stack_a, stack_b, 'b');
	}
}

void	get_closest(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (lowest_value(*stack_a)->index == 0)
		ft_pa_pb(stack_a, stack_b, 'b');
	else if (lowest_value(*stack_a)->index == 1)
	{
		ft_ra_rb_rr(*stack_a, *stack_b, 'a');
		ft_pa_pb(stack_a, stack_b, 'b');
	}
	else if (lowest_value(*stack_a)->index == 2)
	{
		ft_ra_rb_rr(*stack_a, *stack_b, 'a');
		ft_ra_rb_rr(*stack_a, *stack_b, 'a');
		ft_pa_pb(stack_a, stack_b, 'b');
	}
	else if (size == 4)
	{
		ft_rra_rrb_rrr(*stack_a, *stack_b, 'a');
		ft_pa_pb(stack_a, stack_b, 'b');
	}
	else
		five_sort(stack_a, stack_b);
}

void	short_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 3)
		three_sort(stack_a, stack_b);
	else if (size == 4)
	{
		get_closest(stack_a, stack_b);
		three_sort(stack_a, stack_b);
		ft_pa_pb(stack_a, stack_b, 'a');
	}
	else
	{
		get_closest(stack_a, stack_b);
		get_closest(stack_a, stack_b);
		three_sort(stack_a, stack_b);
		ft_pa_pb(stack_a, stack_b, 'a');
		ft_pa_pb(stack_a, stack_b, 'a');
	}
}
