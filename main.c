/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:02:47 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/02 17:21:54 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_mlx *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
	{
		free(data->map->matrix[i]);
		i++;
	}
	free(data->map->matrix);
}

void	init_mlx(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
}

int	kill_fdf(t_mlx *data)
{
	free_map(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
 
int	key_board(int keycode, t_mlx *data)
{
	if (keycode == XK_Escape)
		kill_fdf(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	data;
	(void)argv;

	if (argc != 2)
		return (-1);
	
	init_mlx(&data);
	read_file(argv[1], &data);
	mlx_key_hook(data.win_ptr, key_board, &data);
	mlx_loop(data.mlx_ptr);
//	free_map(data);
}
