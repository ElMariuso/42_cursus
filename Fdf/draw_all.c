/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:54:38 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 16:18:24 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_a_line(t_env	fdf, int pos_x, int pos_y, int i_pos)
{
	int		i;
	t_point	begin;
	t_point	end;

	i = 0;
	begin.x = pos_x;
	begin.y = pos_y;
	begin.z = get_height(fdf.map_env.map[i_pos][i++], fdf.zoom);
	end.x = begin.x + fdf.vec_x.x;
	end.y = begin.y + fdf.vec_x.y;
	end.z = get_height(fdf.map_env.map[i_pos][i++], fdf.zoom);
	if (is_outside(fdf, begin, end) == false)
		bresenham(fdf, begin, end);
	while (i < fdf.map_env.col)
	{
		begin.x = end.x;
		begin.y = end.y;
		begin.z = end.z;
		end.x = begin.x + fdf.vec_x.x;
		end.y = begin.y + fdf.vec_x.y;
		end.z = get_height(fdf.map_env.map[i_pos][i++], fdf.zoom);
		if (is_outside(fdf, begin, end) == false)
			bresenham(fdf, begin, end);
	}
}

void	draw_a_col(t_env	fdf, int pos_x, int pos_y, int i_pos)
{
	int		i;
	t_point	begin;
	t_point	end;

	i = 0;
	begin.x = pos_x;
	begin.y = pos_y;
	begin.z = get_height(fdf.map_env.map[i++][i_pos], fdf.zoom);
	end.x = begin.x - fdf.vec_y.x;
	end.y = begin.y - fdf.vec_y.y;
	end.z = get_height(fdf.map_env.map[i++][i_pos], fdf.zoom);
	if (is_outside(fdf, begin, end) == false)
		bresenham(fdf, begin, end);
	while (i < fdf.map_env.row)
	{
		begin.x = end.x;
		begin.y = end.y;
		begin.z = end.z;
		end.x = begin.x - fdf.vec_y.x;
		end.y = begin.y - fdf.vec_y.y;
		end.z = get_height(fdf.map_env.map[i++][i_pos], fdf.zoom);
		if (is_outside(fdf, begin, end) == false)
			bresenham(fdf, begin, end);
	}
}

void	draw_all(t_env	fdf, int pos_base_x, int pos_base_y)
{
	int	x;
	int	y;
	int	i;

	x = pos_base_x;
	y = pos_base_y;
	i = 0;
	while (i < fdf.map_env.row)
	{
		draw_a_line(fdf, x, y, i);
		x = x - fdf.vec_y.x;
		y = y - fdf.vec_y.y;
		i++;
	}
	x = pos_base_x;
	y = pos_base_y;
	i = 0;
	while (i < fdf.map_env.col)
	{
		draw_a_col(fdf, x, y, i);
		x = x + fdf.vec_x.x;
		y = y + fdf.vec_x.y;
		i++;
	}
}
