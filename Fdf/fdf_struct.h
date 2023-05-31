/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:57:05 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 15:43:50 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct s_map
{
	int	**map;
	int	row;
	int	col;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_img
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_env
{
	t_map	map_env;
	void	*mlx_ptr;
	void	*win_ptr;
	t_point	win_size;
	void	*img_ptr;
	t_img	img;
	int		height_max;
	int		height_min;
	int		zoom;
	int		pos_x;
	int		pos_y;
	t_point	vec_x;
	t_point	vec_y;
	int		proj;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		diff_pos_x;
	int		diff_pos_y;
}	t_env;

typedef struct s_bre
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
}	t_bre;

#endif
