/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:16:33 by mthiry            #+#    #+#             */
/*   Updated: 2021/09/22 17:47:07 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_toupper(int c)
{
	if (c < 0 || c > 255)
		return (c);
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return ((unsigned char) c);
}