/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:02:47 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/07 20:39:13 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->matrix != NULL)
	{
		while (i < map->height)
		{
			free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
}

void	init_mlx(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
}

int	kill_fdf(t_mlx *data)
{
	free_map(data->map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	exit (0);
}

int	key_board(int keycode, t_mlx *data)
{
//	printf("The %d key has been pressed\n\n", keycode);
	zoom(keycode, data);
	arrows(keycode, data);
	rotate(keycode, data);
	views(keycode, data);
	if (keycode == XK_Escape)
		kill_fdf(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	data;
	t_map	map;

	if (argc != 2)
		return (-1);
	data.map = &map;
	init_mlx(&data);
	init_map(&map);
	read_file(argv[1], &map);
	draw(&data);
	mlx_key_hook(data.win_ptr, key_board, &data);
	mlx_hook(data.win_ptr, 17, 0, kill_fdf, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
