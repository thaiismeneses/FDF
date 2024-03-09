/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:22:33 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/09 14:03:05 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 

void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->z = 0;
	map->z2 = 0;
	map->zoom = 15;
	map->color = 0xffffff;
	map->matrix = NULL;
	map->move_x = (WIN_WIDTH - map->width) / 2;
	map->move_y = WIN_HEIGHT / 5;
	map->angle_x = 0.816 ;
	map->angle_y = 0.816;
}

void	config_map(t_point *point, float *x2, float *y2, t_mlx *data)
{
	config_zoom(point, x2, y2, data);
	isometric(&point->x, &point->y, data->map->z, data);
	isometric(x2, y2, data->map->z2, data);
	config_arrows(point, x2, y2, data);
}

void	config_zoom(t_point *point, float *x2, float *y2, t_mlx *data)
{
	point->x *= data->map->zoom;
	point->y *= data->map->zoom;
	*x2 *= data->map->zoom;
	*y2 *= data->map->zoom;
}

void	config_arrows(t_point *point, float *x2, float *y2, t_mlx *data)
{
	point->x += data->map->move_x;
	point->y += data->map->move_y;
	*x2 += data->map->move_x;
	*y2 += data->map->move_y;
}

int	paint(int *z)
{
	if (*z > 0)
		return (0xe80c0c);
	return (0xffffff);
}
