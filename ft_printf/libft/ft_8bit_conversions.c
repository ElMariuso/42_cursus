/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_8bit_conversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:38:11 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/21 18:44:21 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_int_to_8bit_binary(int c)
{
	int		i;
	char	*bin;
	int		quotient;
	int		temp;

	i = 0;
	bin = calloc (8, sizeof(char));
	if (!bin)
		return (NULL);
	while (i != 8)
		bin[i++] += 48;
	quotient = c;
	i--;
	while (quotient != 0)
	{
		temp = quotient % 2;
		temp += 48;
		bin[i] = temp;
		quotient = quotient / 2;
		i--;
	}
	return (bin);
}
