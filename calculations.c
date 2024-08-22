/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 21:36:06 by mleibeng          #+#    #+#             */
/*   Updated: 2024/01/10 21:02:07 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_angle(float *x, float *y, int z, t_matrix *matrix)
{
	*x = (*x - *y) * cos(matrix->cos_angle);
	*y = (*x + *y) * sin(matrix->sin_angle) - z;
}

void	next_coords(float *x, float dx, float *y, float dy)
{
	*x += dx;
	*y += dy;
}

void	move_map(float *x1, float *y1, t_matrix *matrix)
{
	matrix->data->x += matrix->data->x_pos;
	matrix->data->y += matrix->data->y_pos;
	*x1 += matrix->data->x_pos;
	*y1 += matrix->data->y_pos;
}

void	change_angle_func(float *x1, float *y1, t_matrix *matrix)
{
	change_angle(&matrix->data->x, &matrix->data->y, matrix->data->z, matrix);
	change_angle(x1, y1, matrix->data->z1, matrix);
}

float	compare_func(float dx, float dy)
{
	if (fabs(dx) > fabs(dy))
		return (fabs(dx));
	else
		return (fabs(dy));
}
