/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:06:29 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 13:59:08 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h" 

void	push_make_second_empty(t_stack	**first, t_stack	**second)
{
	(*second)->next = *first;
	(*first)->previous = *second;
	*first = (*first)->previous;
	*second = NULL;
	ft_update_indexs(*first);
}

void	push_first_exist(t_stack **first, t_stack **second)
{
	t_stack	*tmp;

	tmp = *second;
	*second = (*second)->next;
	(*second)->previous = NULL;
	tmp->next = *first;
	(*first)->previous = tmp;
	*first = (*first)->previous;
	ft_update_indexs(*first);
	ft_update_indexs(*second);
}

void	ft_push_create_first(t_stack	**first, t_stack	**second)
{
	*first = *second;
	*second = (*second)->next;
	(*second)->previous = NULL;
	(*first)->next = NULL;
	(*first)->index = 0;
	(*first)->previous = NULL;
	ft_update_indexs(*second);
}

void	ft_push(t_stack **first, t_stack **second)
{
	if ((*second)->next == NULL)
		push_make_second_empty(first, second);
	else if (*first)
		push_first_exist(first, second);
	else
		ft_push_create_first(first, second);
}

void	ft_pa_pb(t_stack	**stack_a, t_stack	**stack_b, char command)
{
	if (command == 'a')
	{
		ft_printf("pa\n");
		ft_push(stack_a, stack_b);
	}
	else if (command == 'b')
	{
		ft_printf("pb\n");
		ft_push(stack_b, stack_a);
	}
	else
		error("Error\n");
}
