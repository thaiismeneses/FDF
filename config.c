/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:31:03 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/01 19:04:45 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	defaults(t_mlx *data)
{
	data->width = 0;
	data->height = 0;
	data->z_matrix = NULL;
	data->zoom = 15;
	data->color = 0xffffff;
	data->shift_x = 0;
	data->shift_y = 0;
	data->z = 0;
	data->z2 = 0;
	data->x_increment = 0;
	data->y_increment = 0;
	data->x = 0;
	data->y = 0;
}


