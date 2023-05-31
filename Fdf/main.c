/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:35:36 by mthiry            #+#    #+#             */
/*   Updated: 2022/05/16 17:05:37 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	is_a_right_file(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.')
		{
			if (argv[i + 1] == 'f')
			{
				if (argv[i + 2] == 'd')
				{
					if (argv[i + 3] == 'f')
					{
						if (argv[i + 4] == '\0')
							return (true);
					}
				}
			}
		}
		i++;
	}
	return (false);
}

int	main(int argc, char	**argv)
{
	t_env	fdf;
	t_map	map;

	if (argc != 2)
		print_error_and_exit(strerror(errno));
	if (is_a_right_file(argv[1]) != true)
		print_error_and_exit(strerror(errno));
	map = init_map(argv[1]);
	fdf.map_env = map;
	init_mlx(&fdf, 1560, 1080);
	env_mlx(&fdf);
	free_all_int_array(fdf.map_env.map, fdf.map_env.row);
	return (0);
}
