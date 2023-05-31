/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:35:51 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 16:29:19 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "fdf_struct.h"
# include <stdbool.h>
# include <errno.h>
# include <math.h>

void	free_all_array(char	**array);
void	free_all_int_array(int **array, int row);
void	print_error_and_exit(const char	*s);
void	close_error_and_exit(int fd, const char	*s);
void	free_error_and_exit(char	*s, const char	*sm);
void	free_strarray_error_and_exit(char	**strarray, const char	*s);
char	**get_args_map(char	*args);
int		get_row(char	**args_map);
int		get_col(char	**args_map);
t_map	init_map(char	*args);
void	init_mlx(t_env	*fdf, int x_size, int y_size);
void	get_vec(t_env	*fdf);
void	init_position(t_env	*fdf);
void	env_mlx(t_env	*fdf);
void	draw_all(t_env	fdf, int pos_base_x, int pos_base_y);
void	bresenham(t_env	fdf, t_point	begin, t_point	end);
int		get_height(int height_value, int zoom);
bool	is_outside(t_env	fdf, t_point	begin, t_point	end);

int		key_hook_manager(int keycode, t_env	*fdf);
void	redrawing(t_env *fdf);
int		exit_fdf(int keycode, t_env	*fdf);
int		red_cross(t_env	*fdf);
void	exit_error_fdf(t_env *fdf, char	*s);

#endif
