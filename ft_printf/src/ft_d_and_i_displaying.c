/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_and_i_displaying.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:29:41 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/22 16:24:42 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_d_and_i_displaying(va_list args, int nb_char)
{
	int		len;
	char	*tmp_format;

	tmp_format = ft_itoa(va_arg(args, int));
	if (!tmp_format)
		return (0);
	len = ft_strlen(tmp_format);
	write(1, tmp_format, len);
	free(tmp_format);
	return (nb_char + len);
}
