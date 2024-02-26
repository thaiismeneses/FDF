/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:29:53 by thfranco         #+#    #+#             */
/*   Updated: 2024/02/26 19:41:07 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	t_mlx	*data;

	data = (t_mlx *)malloc(sizeof(t_mlx));
	read_file(argv[1], data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win, arrow_control, &data);
	mlx_loop(data->mlx);
	return (0);
}
