/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:30:34 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/04 18:16:18 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_and_null(char	*args1, char	*args2)
{
	free(args1);
	free(args2);
	return (NULL);
}

char	*ft_reading(int fd, char *save)
{
	int		rd;
	char	*buf;

	rd = 1;
	buf = (char *) malloc (4 * sizeof(char));
	if (!buf)
		ft_free_and_null(buf, NULL);
	while (rd > 0)
	{
		rd = read(fd, buf, 3);
		if (rd == -1)
			ft_free_and_null(buf, NULL);
		else if (!rd)
			break ;
		buf[rd] = '\0';
		save = ft_freestrjoin(save, buf);
		if (ft_strchr(buf, '\n'))
		{
			free(buf);
			break ;
		}
	}
	if (rd == 0)
		return (ft_free_and_null(buf, NULL));
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	i++;
	line = (char *) malloc (i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	while (j != i)
	{
		line[j] = save[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*save = NULL;

	if (fd == -1)
		return (0);
	tmp = ft_reading(fd, save);
	if (!tmp)
		return (NULL);
	else if (tmp[0] == '\0')
		return (ft_free_and_null(tmp, save));
	line = ft_get_line(tmp);
	if (!line)
		return (ft_free_and_null(tmp, save));
	if (!ft_strchr(tmp, '\n'))
	{
		save = 0;
		free(tmp);
		return (line);
	}
	save = ft_strdup(ft_strchr(tmp, '\n') + 1);
	if (!save)
		return (ft_free_and_null(tmp, line));
	free(tmp);
	return (line);
}
