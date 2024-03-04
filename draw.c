/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:25 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/04 13:42:53 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	algorithm_brensenham(float x2, float y2, t_map *map, t_mlx *data)
{
	int	steps;
	
	map->x_increment = x2 - map->x;
	map->y_increment = y2 - map->y;
	steps = fmax(fabs(map->x_increment), fabs(map->y_increment));
	map->x_increment /= steps;
	map->y_increment /= steps;
	while (fabs(map->x - x2) > 0.01 || fabs(map->y - y2) > 0.01)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, map->x, map->y,0xffffff);
		map->x += map->x_increment;
		map->y += map->y_increment;
	}
}

void	draw(t_map *map, t_mlx *data)
{
	int x;
	int y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x < map->width - 1)
				algorithm_brensenham(x + 1, y, map, data);
			if (y < map->height - 1)
				algorithm_brensenham(x, y + 1, map, data);
			x++;
		}
		y++;
	}
}
