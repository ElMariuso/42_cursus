/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:39:00 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 13:59:24 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_reverse_rotate(t_stack *stack)
{
	t_stack	*first_elem;
	int		last_value;
	int		tmp;
	int		tmp_next;

	first_elem = stack;
	last_value = ft_stacklast(stack)->value;
	tmp_next = stack->value;
	stack = stack->next;
	while (stack)
	{
		tmp = tmp_next;
		tmp_next = stack->value;
		stack->value = tmp;
		stack = stack->next;
	}
	first_elem->value = last_value;
}

void	ft_rra_rrb_rrr(t_stack	*stack_a, t_stack	*stack_b, char command)
{
	if (command == 'a')
	{
		ft_printf("rra\n");
		ft_reverse_rotate(stack_a);
	}
	else if (command == 'b')
	{
		ft_printf("rrb\n");
		ft_reverse_rotate(stack_b);
	}
	else if (command == 'r')
	{
		ft_printf("rrr\n");
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
	else
		error("Error\n");
}
