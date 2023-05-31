/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:32:57 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 12:31:53 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	redrawing(t_env *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr,
			fdf->win_size.x, fdf->win_size.y);
	if (fdf->img_ptr != NULL)
	{
		fdf->img.addr = mlx_get_data_addr(fdf->img_ptr,
				&fdf->img.bits_per_pixel, &fdf->img.line_length,
				&fdf->img.endian);
		draw_all(*fdf, fdf->pos_x, fdf->pos_y);
		mlx_put_image_to_window(fdf->mlx_ptr,
			fdf->win_ptr, fdf->img_ptr, 0, 0);
	}
	else
		exit_error_fdf(fdf, strerror(errno));
}

bool	is_outside(t_env	fdf, t_point	begin, t_point	end)
{
	if (begin.x > fdf.win_size.x && end.x > fdf.win_size.x)
		return (true);
	else if (begin.y - begin.z > fdf.win_size.y
		&& end.y - end.z > fdf.win_size.y)
		return (true);
	else if (begin.x < 0 && end.x < 0)
		return (true);
	else if (begin.y < 0 && end.x < 0)
		return (true);
	else
		return (false);
}

int	get_height(int height_value, int zoom)
{
	int	height;

	height = (height_value * zoom) / 6;
	return (height);
}

void	get_vec(t_env	*fdf)
{
	if (fdf->proj == 0)
	{
		fdf->vec_x.x = ((fdf->zoom) * cos(120));
		fdf->vec_x.y = ((fdf->zoom) * sin(120));
		fdf->vec_y.x = ((fdf->zoom) * cos(-120));
		fdf->vec_y.y = ((fdf->zoom) * sin(-120));
	}
	else if (fdf->proj == 1)
	{
		fdf->vec_x.x = ((fdf->zoom));
		fdf->vec_x.y = 0;
		fdf->vec_y.x = ((fdf->zoom) * cos(-120));
		fdf->vec_y.y = ((fdf->zoom) * sin(-120));
	}
}
