/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:10:11 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 13:58:32 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_all_array(char	**splitted_stack)
{
	int	i;

	i = 0;
	while (splitted_stack[i])
	{
		free(splitted_stack[i]);
		i++;
	}
	free(splitted_stack);
}

void	free_stack(t_stack	*stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_all_stacks(t_stack	*stack_a, t_stack	*stack_b)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	while (stack_b)
	{
		tmp = stack_b;
		stack_b = stack_b->next;
		free(tmp);
	}
}

void	free_array_and_error(char	**splitted_stack)
{
	free_all_array(splitted_stack);
	error("Error\n");
}

void	free_stack_and_error(t_stack	*stack)
{
	free_stack(stack);
	error("Error\n");
}
