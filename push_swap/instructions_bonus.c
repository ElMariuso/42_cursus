/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:54:42 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/04 18:24:52 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

void	ft_push_manager(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0
		&& *stack_b != NULL)
		ft_push(stack_a, stack_b);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0
		&& *stack_a != NULL)
		ft_push(stack_b, stack_a);
	else
	{
		free(line);
		free(*stack_b);
		free_stack_and_error(*stack_a);
	}
}

void	ft_rrr_manager(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0
		&& *stack_a != NULL && stack_size(*stack_a) > 2)
		ft_reverse_rotate(*stack_a);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0
		&& *stack_a != NULL && stack_size(*stack_b) > 2)
		ft_reverse_rotate(*stack_b);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0
		&& *stack_a != NULL && *stack_b != NULL && stack_size(*stack_a) > 2
		&& stack_size(*stack_b) > 2)
	{
		ft_reverse_rotate(*stack_a);
		ft_reverse_rotate(*stack_b);
	}
	else
	{
		free(line);
		free(*stack_b);
		free_stack_and_error(*stack_a);
	}
}

void	ft_rotate_manager(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0
		&& *stack_a != NULL && stack_size(*stack_a) > 2)
		ft_rotate(*stack_a);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0
		&& *stack_b != NULL && stack_size(*stack_b) > 2)
		ft_rotate(*stack_b);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0
		&& *stack_a != NULL && *stack_b != NULL && stack_size(*stack_a) > 2
		&& stack_size(*stack_b) > 2)
	{
		ft_rotate(*stack_a);
		ft_rotate(*stack_b);
	}
	else
	{
		free(line);
		free(*stack_b);
		free_stack_and_error(*stack_a);
	}
}

void	ft_swap_manager(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0
		&& *stack_a != NULL && stack_size(*stack_a) > 2)
		ft_swap(*stack_a);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0
		&& *stack_b != NULL && stack_size(*stack_b) > 2)
		ft_swap(*stack_b);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0
		&& *stack_a != NULL && *stack_b != NULL && stack_size(*stack_a) > 2
		&& stack_size(*stack_b) > 2)
	{
		ft_swap(*stack_a);
		ft_swap(*stack_b);
	}
	else
	{
		free(line);
		free(*stack_b);
		free_stack_and_error(*stack_a);
	}
}

void	ft_execute_instructions(t_stack	**fi, t_stack **se, char *line)
{
	if (line[0] == 's')
		ft_swap_manager(fi, se, line);
	else if (line[0] == 'r')
	{
		if (line[1] == 'r')
			ft_rrr_manager(fi, se, line);
		else
			ft_rotate_manager(fi, se, line);
	}
	else if (line[0] == 'p')
		ft_push_manager(fi, se, line);
	else
	{
		free(line);
		free(*se);
		free_stack_and_error(*fi);
	}
}
