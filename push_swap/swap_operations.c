/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:46:11 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 14:00:16 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack	*stack)
{
	int	tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void	ft_sa_sb_ss(t_stack	*stack_a, t_stack	*stack_b, char command)
{
	if (command == 'a')
	{
		ft_printf("sa\n");
		ft_swap(stack_a);
	}
	else if (command == 'b')
	{
		ft_printf("sb\n");
		ft_swap(stack_b);
	}
	else if (command == 's')
	{
		ft_printf("ss\n");
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else
		error("Error\n");
}
