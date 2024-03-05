/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:41:01 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/05 20:26:42 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int keycode, t_mlx *data)
{
	if (keycode == XK_i)
		data->map->zoom -= 1;
	if (keycode == XK_o)
		data->map->zoom += 1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
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
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
}
