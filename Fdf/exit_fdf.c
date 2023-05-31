/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:04:56 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 16:11:22 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error_fdf(t_env *fdf, char *s)
{
	ft_printf("%s\n", s);
	if (fdf->win_ptr != NULL)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	if (fdf->img_ptr != NULL)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	free_all_int_array(fdf->map_env.map, fdf->map_env.row);
	exit(EXIT_FAILURE);
}

int	exit_fdf(int keycode, t_env *fdf)
{
	(void)keycode;
	if (fdf->map_env.map != NULL)
		free_all_int_array(fdf->map_env.map, fdf->map_env.row);
	if (fdf->img_ptr != NULL)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	if (fdf->win_ptr != NULL)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int	red_cross(t_env	*fdf)
{
	if (fdf->map_env.map != NULL)
		free_all_int_array(fdf->map_env.map, fdf->map_env.row);
	if (fdf->img_ptr != NULL)
		mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	if (fdf->win_ptr != NULL)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
