/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:31:41 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 16:27:50 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height_max(t_env	*fdf)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = 0;
	while (i < fdf->map_env.row)
	{
		while (j < fdf->map_env.col)
		{
			if (fdf->map_env.map[i][j] > max)
				max = fdf->map_env.map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (max);
}

int	get_height_min(t_env	*fdf)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	j = 0;
	min = 0;
	while (i < fdf->map_env.row)
	{
		while (j < fdf->map_env.col)
		{
			if (fdf->map_env.map[i][j] < min)
				min = fdf->map_env.map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (min);
}

void	init_mlx(t_env	*fdf, int x_size, int y_size)
{
	fdf->mlx_ptr = mlx_init();
	fdf->height_max = get_height_max(fdf);
	fdf->height_min = get_height_min(fdf);
	fdf->win_size.x = x_size;
	fdf->win_size.y = y_size;
	fdf->proj = 0;
}

void	init_position(t_env *fdf)
{
	fdf->pos_x = (fdf->win_size.x / 2)
		- (fdf->vec_x.x * (fdf->map_env.col / 4));
	fdf->pos_y = (fdf->win_size.y / 2)
		- ((fdf->vec_x.y * fdf->map_env.col)) + 100;
}
