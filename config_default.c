/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <thfranco@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:31:03 by thfranco          #+#    #+#             */
/*   Updated: 2024/02/26 20:09:16 by thfranco         ###   ########.fr       */
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
	data->shifit = 0;
}
