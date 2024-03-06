/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 19:41:01 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/06 16:15:06 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int keycode, t_mlx *data)
{
	if (keycode == XK_KP_Subtract)
		data->map->zoom -= 1;
	if (keycode == XK_KP_Add)
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
