/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thafranco <thfranco@student.42.rio>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:29:53 by thafranco         #+#    #+#             */
/*   Updated: 2024/02/20 19:57:31 by thafranco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_mlx	*data;
	int i;
	int	j;
	
	data = (t_mlx*)malloc(sizeof(t_mlx));
	read_file(argv[1], data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%d ", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	//data->mlx = mlx_init();
	//data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "mlx 42");
	//mlx_key_hook(data->win, key_board, &data);
	//mlx_loop(data->mlx);
	return (0);
}
