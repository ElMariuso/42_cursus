/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:54:28 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/04 18:02:45 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	ft_get_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = "";
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		else
			ft_execute_instructions(stack_a, stack_b, line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = init_stack(argc, argv, stack_a);
	ft_simplification(stack_a);
	if (is_sorted(stack_a) == true)
		ft_printf("OK\n");
	else
	{
		ft_get_instructions(&stack_a, &stack_b);
		if (is_sorted(stack_a) == true && stack_b == NULL)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_stack(stack_b);
	free_stack(stack_a);
	return (0);
}
