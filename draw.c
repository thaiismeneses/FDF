/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:29:16 by thfranco          #+#    #+#             */
/*   Updated: 2024/02/25 21:05:04 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
int max(int a, int b)
{
	if (a > b)
		return(a);
	return (b);
}

int mod(int a)
{
	if (a > 0)
		return (-a);
	return (a);
}

float	mod(flaot i)
{
	if (i < 0)
		return (-i);
	return (i);
}
void	algorithm_brensenham(int x, int y, int x2, int y2, t_mlx *data)
{
	int dx;
	int dy;
	int p;
	
	x *= data->zoom;
	y *= data->zoom;
	x2 *= data->zoom;
	y2 *= data->zoom;
	
	dx = x2 - x;
	dy = y2 - y;
	p = 2*dx - dy;
	
	
	while (x <= x2)
	{
			mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);
			//put_pixel(x, y);
			x++;
			if (p < 0)
				p = p + 2*dy;
			else
			{
				p = p + 2*dy - dx;
				y++;
			}
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
			algorithm_brensenham(x, y, x + 1, y, data);
			algorithm_brensenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
