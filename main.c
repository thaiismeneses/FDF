/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:29:53 by thfranco         #+#    #+#             */
/*   Updated: 2024/02/29 20:56:44 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	t_mlx	data;
	
	defaults(&data);
	read_file(argv[1], data);

	int i = 0;
	int j;
	printf("%d\n", data.height);
	printf("%d\n", data.width);

	while (i < data.height)
	{
		j = 0;
		while (j < data.width)
		{
			printf("%3d", data.z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
/*	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	draw(data);
	mlx_key_hook(data->win, key_board, &data);
	m*lx_loop(data->mlx);*/
	i = 0;
	while (i <= data.height)
	{
		free(data.z_matrix[i]);
		i++;
	}
	free(data.z_matrix);
	return (0);
}
