/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_displaying.c                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:48:28 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/22 16:39:51 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_percent_displaying(int nb_char)
{
	char	tmp_char_format;

	tmp_char_format = '%';
	write(1, &tmp_char_format, 1);
	return (nb_char + 1);
}
