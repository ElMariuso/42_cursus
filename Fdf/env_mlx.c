/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:36:38 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 16:29:59 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	hook_manager(t_env	*fdf)
{
	mlx_hook(fdf->win_ptr, 17, (1L << 5), red_cross, fdf);
	mlx_hook(fdf->win_ptr, 2, (1L << 0), key_hook_manager, fdf);
}

void	init_values(t_env	*fdf)
{
	fdf->zoom = 6;
	get_vec(fdf);
	init_position(fdf);
}

void	env_mlx(t_env	*fdf)
{
	if (fdf->mlx_ptr != NULL)
	{
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
				fdf->win_size.x, fdf->win_size.y, "fdf");
		if (fdf->win_ptr != NULL)
		{
			fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,
					fdf->win_size.x, fdf->win_size.y);
			if (fdf->img_ptr != NULL)
			{
				fdf->img.addr = mlx_get_data_addr(fdf->img_ptr,
						&fdf->img.bits_per_pixel,
						&fdf->img.line_length, &fdf->img.endian);
				init_values(fdf);
				draw_all(*fdf, fdf->pos_x, fdf->pos_y);
				mlx_put_image_to_window(fdf->mlx_ptr,
					fdf->win_ptr, fdf->img_ptr, 0, 0);
				hook_manager(fdf);
				mlx_loop(fdf->mlx_ptr);
			}
		}
	}
	exit_error_fdf(fdf, strerror(errno));
}
