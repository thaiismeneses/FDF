/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:29:53 by thfranco         #+#    #+#             */
/*   Updated: 2024/03/01 18:08:30 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	t_mlx	*data;
	
	data = (t_mlx *)malloc(sizeof(t_mlx));
//	ft_memset(data, 0, sizeof(t_mlx));
	defaults(data);
	read_file(argv[1], data);

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	draw(data);
	mlx_key_hook(data->win, key_board, &data);
	mlx_loop(data->mlx);
	int i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data);
	return (0);
}
