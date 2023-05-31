/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_displaying.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:14:31 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/22 16:20:45 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_c_displaying(va_list args, int nb_char)
{
	unsigned char	tmp_char_format;

	tmp_char_format = (unsigned char)va_arg(args, int);
	write(1, &tmp_char_format, 1);
	return (nb_char + 1);
}
