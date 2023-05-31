/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:07:33 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 14:00:06 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_get_bits(int size)
{
	int	max_num;
	int	max_bits;

	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;
	j = 0;
	size = stack_size(*stack_a);
	max_bits = ft_get_bits(size);
	while (i < max_bits || is_sorted(*stack_a) == false)
	{
		while (j < size && is_sorted(*stack_a) == false)
		{
			if (((*stack_a)->value >> i) & 1)
				ft_ra_rb_rr(*stack_a, *stack_b, 'a');
			else
				ft_pa_pb(stack_a, stack_b, 'b');
			j++;
		}
		j = 0;
		while (*stack_b != NULL)
			ft_pa_pb(stack_a, stack_b, 'a');
		i++;
	}
}
