/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:07:34 by mleibeng          #+#    #+#             */
/*   Updated: 2024/01/10 21:08:38 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_height_calc(float x1, float y1, t_matrix *matrix)
{
	int	current_y;
	int	current_x;

	current_y = (int)matrix->y_iter;
	current_x = (int)matrix->x_iter;
	matrix->data->z = matrix->map[current_y][current_x] * matrix->data->height;
	matrix->data->z1 = matrix->map[(int)y1][(int)x1] * matrix->data->height;
}

void	apply_zoom(float *x1, float *y1, t_matrix *matrix)
{
	*x1 *= matrix->data->zoom;
	*y1 *= matrix->data->zoom;
	matrix->data->x = matrix->x_iter * matrix->data->zoom;
	matrix->data->y = matrix->y_iter * matrix->data->zoom;
}

void	calc_dimension(float *dx, float *dy, t_matrix *matrix)
{
	int	calc;

	*dx = (matrix->data->x1 - matrix->data->x);
	*dy = (matrix->data->y1 - matrix->data->y);
	calc = compare_func(*dx, *dy);
	*dx /= calc;
	*dy /= calc;
}

void	calc_diff(float *x1, float *y1, t_matrix *matrix)
{
	matrix->x_diff = (int)(matrix->data->x - *x1);
	matrix->y_diff = (int)(matrix->data->y - *y1);
}
