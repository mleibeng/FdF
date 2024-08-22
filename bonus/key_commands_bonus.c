/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:44:25 by mleibeng          #+#    #+#             */
/*   Updated: 2024/01/10 23:59:56 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	movement_commands(mlx_key_data_t keydata, t_matrix *matrix)
{
	if (keydata.key == MLX_KEY_UP)
		matrix->data->y_offset -= 10;
	if (keydata.key == MLX_KEY_LEFT)
		matrix->data->x_offset -= 10;
	if (keydata.key == MLX_KEY_DOWN)
		matrix->data->y_offset += 10;
	if (keydata.key == MLX_KEY_RIGHT)
		matrix->data->x_offset += 10;
	new_img_gen(matrix, 1);
}

void	change_view(mlx_key_data_t keydata, t_matrix *matrix)
{
	if (keydata.key == MLX_KEY_V)
		matrix->data->view_angle = 0;
	else if (keydata.key == MLX_KEY_I)
		matrix->data->view_angle = 1;
	new_img_gen(matrix, 1);
}

void	change_scalability(mlx_key_data_t keydata, t_matrix *matrix)
{
	if (keydata.key == MLX_KEY_G)
	{
		matrix->cos_angle += 0.1;
		matrix->sin_angle += 0.1;
	}
	if (keydata.key == MLX_KEY_H)
	{
		matrix->sin_angle -= 0.1;
		matrix->cos_angle -= 0.1;
	}
	new_img_gen(matrix, 1);
}

void	change_height(mlx_key_data_t keydata, t_matrix *matrix)
{
	if (keydata.key == MLX_KEY_O)
		matrix->data->height -= 0.2;
	else if (keydata.key == MLX_KEY_P)
		matrix->data->height += 0.2;
	new_img_gen(matrix, 1);
}

void	scroll_func(double xdelta, double ydelta, void *param)
{
	t_matrix	*matrix;

	matrix = (t_matrix *)param;
	if (ydelta > 0)
	{
		if (matrix->data->zoom >= 0)
			matrix->data->zoom -= 1;
	}
	else if (ydelta < 0)
	{
		if (matrix->data->zoom <= 150)
			matrix->data->zoom += 1;
	}
	if (xdelta < 0)
	{
		if (matrix->data->zoom >= 0)
			matrix->data->zoom += 1;
	}
	else if (xdelta > 0)
	{
		if (matrix->data->zoom <= 150)
			matrix->data->zoom -= 1;
	}
	new_img_gen(matrix, 1);
}
