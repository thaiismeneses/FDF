/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:31:03 by thfranco          #+#    #+#             */
/*   Updated: 2024/02/28 19:49:38 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	defaults(t_mlx *data)
{
	data->width = 0;
	data->height = 0;
	data->z_matrix = NULL;
	data->zoom = 20;
	data->color = 0xffffff;
	data->shift_x = 0;
	data->shift_y = 0;
	data->z = 0;
	data->z2 = 0;
}

