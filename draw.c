/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:29:16 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/01 19:22:12 by thfranco         ###   ########.fr       */
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

void	zoom(float x2, float y2, t_mlx *data)
{
	data->x *= data->zoom;
	data->y *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
}

void	position(float x2, float y2, t_mlx *data)
{
	data->x += data->shift_x;
	data->y += data->shift_y;
	x2 += data->shift_x;
	y2 += data->shift_y;
}


/*void	operations(float x2, float y2, t_mlx *data)
{
	zoom(x2, y2, data);

	position(x2, y2, *data);
}*/

void	algorithm_brensenham(float x2, float y2, t_mlx *data)
{
	int steps;

	steps = 0;
	data->z = data->z_matrix[(int)data->y][(int)data->x];
	data->z2 = data->z_matrix[(int)y2][(int)x2];

	//---------Zoom---------
//	x *= data->zoom;
//	y *= data->zoom;
//	x2 *= data->zoom;
//	y2 *= data->zoom;
	//-------color-----r
	data->color = (data->z) ? 0xe80c0c : 0xffffff;
	//------3D-----------
	isometric(&data->x, &data->y, data->z);
	isometric(&x2, &y2, data->z2);
	//------shift----------
//	x += data->shift_x;
//	y += data->shift_y;
//	x2 += data->shift_x;
//	y2 += data->shift_y;

	data->x_increment = x2 - data->x;
	data->y_increment = y2 - data->y;
	steps = fmax(fabs(data->x_increment), fabs(data->y_increment));
	data->x_increment /= steps;
	data->y_increment /= steps;

	while ((int)(data->x - x2) || (int)(data->y - y2))
	{
			mlx_pixel_put(data->mlx, data->win, data->x, data->y, data->color);
			data->x += data->x_increment;
			data->y += data->y_increment;
	}
}

void	draw(t_mlx *data)
{
	float x;
	float y;
	
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				algorithm_brensenham(data->x + 1, data->y, data);
			if (y < data->height - 1)
				algorithm_brensenham(data->x, data->y + 1, data);
			x++;
		}
		y++;
	}
}
