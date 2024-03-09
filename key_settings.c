/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:41:01 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/09 13:29:54 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int keycode, t_mlx *data)
{
	if (keycode == XK_KP_Subtract)
		data->map->zoom -= 1;
	if (keycode == XK_KP_Add)
		data->map->zoom += 1;
}

void	arrows(int keycode, t_mlx *data)
{
	if (keycode == XK_Up)
		data->map->move_y -= 10;
	if (keycode == XK_Down)
		data->map->move_y += 10;
	if (keycode == XK_Left)
		data->map->move_x -= 10;
	if (keycode == XK_Right)
		data->map->move_x += 10;
}

void	rotate(int keycode, t_mlx *data)
{
	if (keycode == XK_w)
		data->map->angle_y += 0.25;
	if (keycode == XK_s)
		data->map->angle_y -= 0.25;
	if (keycode == XK_a)
		data->map->angle_x -= 0.25;
	if (keycode == XK_d)
		data->map->angle_x += 0.25;
}

void	views(int keycode, t_mlx *data)
{
	if (keycode == XK_i)
	{
		data->map->angle_x = 0.52;
		data->map->angle_y = 0.52;
	}
	if (keycode == XK_p)
	{
		data->map->angle_x = 0.80;
		data->map->angle_y = 0.80;
	}
	if (keycode == XK_b)
	{
		data->map->angle_x = 0.73;
		data->map->angle_y = 0.122173;
	}
}
