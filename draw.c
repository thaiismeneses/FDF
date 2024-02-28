/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:29:16 by thfranco          #+#    #+#             */
/*   Updated: 2024/02/28 19:49:41 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*int paint(int z)
{
	if (z > 0)
		return (0xe80c0c);
	return (0xffffff);
}*/

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	algorithm_brensenham(float x, float y, float x2, float y2, t_mlx *data)
{
	int steps;
	float x_increment;
	float y_increment;

	steps = 0;
	data->z = data->z_matrix[(int)y][(int)x];
	data->z2 = data->z_matrix[(int)y2][(int)x2];
	//---------Zoom---------
	x *= data->zoom;
	y *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
	//-------color-----r
	data->color = (data->z) ? 0xe80c0c : 0xffffff;
	//------3D-----------
	isometric(&x, &y, data->z);
	isometric(&x2, &y2, data->z2);
	//------shift----------
	x += data->shift_x;
	y += data->shift_y;
	x2 += data->shift_x;
	y2 += data->shift_y;

	x_increment = x2 - x;
	y_increment = y2 - y;
	steps = fmax(fabs(x_increment), fabs(y_increment));
	x_increment /= steps;
	y_increment /= steps;

	while ((int)(x - x2) || (int)(y - y2))
	{
			mlx_pixel_put(data->mlx, data->win, x, y, data->color);
			x += x_increment;
			y += y_increment;
	}
}

void	draw(t_mlx *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				algorithm_brensenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				algorithm_brensenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
