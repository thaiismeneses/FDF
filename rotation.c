/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:30:41 by thfranco          #+#    #+#             */
/*   Updated: 2024/03/06 16:47:16 by thfranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(float *x, float *y, int z)
{
	*x = x * cos(angle) + y * -sin(angle);
	*y = x * sin(angle) + y * cos(angle);
	*z = z;
}

void	rotate_x()
{
	*x = x;
	*y = y * cos(angle) + y * -sin(angle);
	*z = y * sin(angle) + z * cos(angle);
}

void	rotate_y()
{
	*x = x * cos(angle) + z * sin(angle);
	*y = y;
	*z = x * -sin(angle) + z * cos(angle);
}
