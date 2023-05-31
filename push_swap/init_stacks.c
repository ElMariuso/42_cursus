/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:24:20 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/04 16:39:40 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_first_elem(char	**splitted_stack)
{
	t_stack	*first_elem;

	first_elem = (t_stack *) malloc (sizeof(t_stack));
	if (!first_elem)
		free_array_and_error(splitted_stack);
	first_elem->value = ft_atoi(*splitted_stack);
	first_elem->index = 0;
	first_elem->is_simplified = false;
	first_elem->next = NULL;
	first_elem->previous = NULL;
	return (first_elem);
}

t_stack	*fill_stack(char	**splitted_stack)
{
	t_stack	*stack;
	t_stack	*new_con;
	t_stack	*first_elem;
	int		i;

	first_elem = init_first_elem(splitted_stack++);
	stack = first_elem;
	i = 1;
	while (*splitted_stack)
	{
		new_con = (t_stack *) malloc (sizeof(t_stack));
		if (!new_con)
		{
			free_all_array(splitted_stack);
			free_stack_and_error(first_elem);
		}
		new_con->value = ft_atoi(*splitted_stack++);
		new_con->index = i++;
		new_con->is_simplified = false;
		new_con->next = NULL;
		new_con->previous = stack;
		stack->next = new_con;
		stack = stack->next;
	}
	return (first_elem);
}

t_stack	*init_stack(int argc, char **argv, t_stack *stack_a)
{
	char	**splitted_stack;

	if (argv[1][0] == '\0')
		error("Error\n");
	if (argc == 2)
	{
		splitted_stack = ft_split(argv[1], ' ');
		if (!splitted_stack)
			error("Error\n");
	}
	else
	{
		splitted_stack = ft_split_add(argv);
		if (!splitted_stack)
			error("Error\n");
	}
	if (is_correct(splitted_stack) == false)
		free_array_and_error(splitted_stack);
	stack_a = fill_stack(splitted_stack);
	free_all_array(splitted_stack);
	return (stack_a);
}
