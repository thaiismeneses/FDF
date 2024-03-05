/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:22:33 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/05 16:44:41 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h" 
#include <stdio.h>
void	init_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->z = 0;
	map->z2 = 0;
	map->zoom = 15;
	map->color = 0xffffff;
	map->matrix = NULL;
}

void	config_map(t_point *point, float *x2, float *y2, t_mlx *data)
{
	config_zoom(point, x2, y2, data);
	isometric(&point->x, &point->y, data->map->z);
	isometric(x2, y2, data->map->z2);
}

void	config_zoom(t_point *point, float *x2, float *y2, t_mlx *data)
{
	point->x *= data->map->zoom;
	point->y *= data->map->zoom;
	*x2 *= data->map->zoom;
	*y2 *= data->map->zoom;
}

void	zoom(int keycode, t_mlx *data)
{
	if (keycode == XK_minus)
		data->map->zoom -= 1;
	if (keycode == XK_plus)
		data->map->zoom += 1;
}

int	paint(int *z)
{
	if (*z > 0)
		return (0xe80c0c);
	return (0xffffff);
}
