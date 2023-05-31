/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:35:40 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 10:14:54 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error_and_exit(const char *s)
{
	ft_printf("[ERROR]: %s\n", s);
	exit(EXIT_FAILURE);
}

void	close_error_and_exit(int fd, const char *s)
{
	close(fd);
	print_error_and_exit(s);
}

void	free_error_and_exit(char *s, const char *sm)
{
	free(s);
	print_error_and_exit(sm);
}

void	free_strarray_error_and_exit(char **strarray, const char *s)
{
	free_all_array(strarray);
	print_error_and_exit(s);
}
