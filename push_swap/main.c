/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:03:31 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/04 15:35:22 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	display_list(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d: %d\n", stack->index, stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char	**argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(argc, argv, stack_a);
	ft_simplification(stack_a);
	if (is_sorted(stack_a) != true)
	{
		if (stack_size(stack_a) == 2)
			ft_sa_sb_ss(stack_a, stack_b, 'a');
		else if (stack_size(stack_a) <= 5)
			short_sort(&stack_a, &stack_b);
		else
			sort(&stack_a, &stack_b);
	}
	free_stack(stack_a);
	return (0);
}
