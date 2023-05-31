/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:22:57 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 13:59:58 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*ft_highest(t_stack	*stack)
{
	t_stack	*value;

	value = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > value->value)
			value = stack;
		stack = stack->next;
	}
	return (value);
}

void	ft_change_simplification(t_stack	*stack, int i)
{
	t_stack	*to_change;

	if (stack->is_simplified == true)
		to_change = ft_highest(stack);
	else
		to_change = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->is_simplified == false)
		{
			if (stack->value < to_change->value)
				to_change = stack;
		}
		stack = stack->next;
	}
	to_change->value = i;
	to_change->is_simplified = true;
}

void	ft_simplification(t_stack	*stack)
{
	int	i;

	i = 0;
	while (i != stack_size(stack))
	{
		ft_change_simplification(stack, i);
		i++;
	}
}
