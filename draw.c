/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:03:25 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/04 21:28:00 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	algorithm_brensenham(t_point point, float x2, float y2, t_mlx *data)
{
	int	steps;
	float	x_increment;
	float	y_increment;
	//t_map	map;
	
	/*point.x *= data->map->zoom;	
	point.y *= data->map->zoom;
	x2 *= data->map->zoom;
	y2 *= data->map->zoom;*/
	
	config_zoom(&point, &x2, &y2, data);
	x_increment = x2 - point.x;
	y_increment = y2 - point.y;
	steps = fmax(fabs(x_increment), fabs(y_increment));
	x_increment /= steps;
	y_increment /= steps;
	while ((int)(point.x - x2) || (int)(point.y - y2))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, point.x, point.y, 0xffffff);
		point.x += x_increment;
		point.y += y_increment;
	}
}

void	draw(t_mlx *data)
{
	t_point point;

	point.y = 0;
	while (point.y < data->map->height)	
	{
		point.x = 0;
		while (point.x < data->map->width)
		{
			if (point.x < data->map->width - 1)
				algorithm_brensenham(point, point.x + 1, point.y, data);
			if (point.y < data->map->height - 1)
				algorithm_brensenham(point, point.x, point.y + 1, data);
			point.x++;
		}
		point.y++;
	}
}






