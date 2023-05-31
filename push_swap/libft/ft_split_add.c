/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:47:50 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/04 15:40:52 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "../push_swap.h"

int	ft_arraylen(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

char	**fill_array(char **args, char **strarray)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (args[i])
	{
		if (args[i][0] == 0)
			free_array_and_error(strarray);
		strarray[j] = ft_strdup(args[i]);
		if (!strarray[j])
			return (NULL);
		i++;
		j++;
	}
	return (strarray);
}

char	**ft_split_add(char	**args)
{
	int		i;
	char	**strarray;

	if (!args)
		error("Error\n");
	i = 0;
	while (args[i])
		i++;
	strarray = (char **) malloc (i * sizeof(char *));
	if (!strarray)
		return (NULL);
	strarray = fill_array(args, strarray);
	if (!strarray)
		return (NULL);
	strarray[i - 1] = NULL;
	return (strarray);
}
