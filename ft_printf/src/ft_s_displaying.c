/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_displaying.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:22:29 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/22 16:58:51 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_s_displaying(va_list args, int nb_char)
{
	int			len;
	const char	*tmp_format;

	tmp_format = va_arg(args, char *);
	if (!tmp_format)
	{
		write (1, "(null)", 6);
		return (nb_char + 6);
	}
	len = ft_strlen(tmp_format);
	write(1, tmp_format, len);
	return (nb_char + len);
}
