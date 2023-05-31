/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:09:15 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 13:59:31 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	int	tmp_first_elem;

	tmp_first_elem = stack->value;
	while (stack->next)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = tmp_first_elem;
}

void	ft_ra_rb_rr(t_stack	*stack_a, t_stack	*stack_b, char command)
{
	if (command == 'a')
	{
		ft_printf("ra\n");
		ft_rotate(stack_a);
	}
	else if (command == 'b')
	{
		ft_printf("rb\n");
		ft_rotate(stack_b);
	}
	else if (command == 'r')
	{
		ft_printf("rr\n");
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else
		error("Error\n");
}
