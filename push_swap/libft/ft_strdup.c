/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 11:24:50 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/04 17:47:05 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_freestrdup(char *s1)
{
	void	*dest;
	size_t	size;

	size = ft_strlen(s1) + 1;
	dest = malloc (size * sizeof (char));
	if (!dest || !s1)
		return (NULL);
	dest = (char *) ft_memcpy(dest, s1, size);
	free(s1);
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	void	*dest;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + 1;
	dest = malloc (size * sizeof (char));
	if (!dest)
		return (NULL);
	return ((char *) ft_memcpy(dest, s1, size));
}
