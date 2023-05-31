/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:04:17 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/03 17:37:43 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	is_only_integers(char **splitted_stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (splitted_stack[i])
	{
		while (splitted_stack[i][j])
		{
			if (splitted_stack[i][j] != '-')
			{
				if (splitted_stack[i][j] < '0' || splitted_stack[i][j] > '9')
					return (false);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

bool	is_lower_than_max(char **splitted_stack)
{
	int	i;

	i = 0;
	while (splitted_stack[i])
	{
		if (ft_atolo(splitted_stack[i]) > 2147483647)
			return (false);
		if (ft_atolo(splitted_stack[i]) < -2147483648)
			return (false);
		i++;
	}
	return (true);
}

bool	is_one_argument(char	**splitted_stack)
{
	int	i;

	i = 0;
	while (splitted_stack[i])
		i++;
	if (i != 1)
		return (false);
	return (true);
}

bool	no_duplicate(char **splitted_stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (splitted_stack[i])
	{
		while (splitted_stack[j])
		{
			if (ft_atoi(splitted_stack[i]) == ft_atoi(splitted_stack[j]))
				return (false);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (true);
}

bool	is_correct(char **splitted_stack)
{
	if (is_only_integers(splitted_stack) == false)
		return (false);
	if (is_lower_than_max(splitted_stack) == false)
		return (false);
	if (is_one_argument(splitted_stack) == false)
		if (no_duplicate(splitted_stack) == false)
			return (false);
	return (true);
}
