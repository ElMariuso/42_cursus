/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:56:56 by mthiry            #+#    #+#             */
/*   Updated: 2022/02/24 18:54:47 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

int	ft_c_displaying(va_list args, int j);
int	ft_s_displaying(va_list args, int j);
int	ft_p_displaying(va_list args, int j);
int	ft_d_and_i_displaying(va_list args, int j);
int	ft_u_displaying(va_list args, int j);
int	ft_x_displaying(va_list args, int j);
int	ft_x_up_displaying(va_list args, int j);
int	ft_percent_displaying(int j);

int	ft_check_format(const char	*format, va_list args, int i, int j);
int	ft_check_next_char(const char *format, int i);

int	ft_printf(const char	*format, ...);

#endif
