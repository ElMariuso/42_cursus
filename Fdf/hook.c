/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:35:31 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 15:43:36 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int keycode, t_env	*fdf)
{
	if (keycode == 69)
	{
		fdf->zoom *= 2;
		if (fdf->zoom > 30000)
			fdf->zoom = 30000;
	}
	else if (keycode == 78)
	{
		fdf->zoom /= 2;
		if (fdf->zoom < 6)
			fdf->zoom = 6;
	}
	get_vec(fdf);
	init_position(fdf);
	fdf->pos_x = fdf->pos_x + fdf->diff_pos_x;
	fdf->pos_y = fdf->pos_y + fdf->diff_pos_y;
	redrawing(fdf);
}

void	move(int keycode, t_env	*fdf)
{
	if (keycode == 0)
	{
		fdf->pos_x -= 20;
		fdf->diff_pos_x -= 20;
	}
	else if (keycode == 1)
	{
		fdf->pos_y += 20;
		fdf->diff_pos_y += 20;
	}
	else if (keycode == 2)
	{
		fdf->pos_x += 20;
		fdf->diff_pos_x += 20;
	}
	else if (keycode == 13)
	{
		fdf->pos_y -= 20;
		fdf->diff_pos_y -= 20;
	}
	redrawing(fdf);
}

void	change_plan(int keycode, t_env	*fdf)
{
	if (keycode == 123)
	{
		fdf->proj -= 1;
		if (fdf->proj < 0)
			fdf->proj = 1;
	}
	else if (keycode == 124)
	{
		fdf->proj += 1;
		if (fdf->proj > 1)
			fdf->proj = 0;
	}
	get_vec(fdf);
	redrawing(fdf);
}

int	key_hook_manager(int keycode, t_env	*fdf)
{
	if (keycode == 53)
		exit_fdf(keycode, fdf);
	if (keycode == 69 || keycode == 78)
		zoom(keycode, fdf);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move(keycode, fdf);
	if (keycode == 123 || keycode == 124)
		change_plan(keycode, fdf);
	return (0);
}
