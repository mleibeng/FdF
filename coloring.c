/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:47:32 by mleibeng          #+#    #+#             */
/*   Updated: 2024/01/10 23:31:04 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color	check_color_value(t_matrix *matrix)
{
	if (matrix->data->z > 0 || matrix->data->z1 > 0)
		return (matrix->data->color_value1);
	else if (matrix->data->z < 0 || matrix->data->z1 < 0)
		return (matrix->data->color_value3);
	else
		return (matrix->data->color_value2);
}

void	change_color_set(mlx_key_data_t keydata, t_matrix *matrix)
{
	if (keydata.key == MLX_KEY_0)
	{
		matrix->data->color_value1 = WHITE;
		matrix->data->color_value2 = RED;
		matrix->data->color_value3 = BLUE;
	}
	else if (keydata.key == MLX_KEY_1)
	{
		matrix->data->color_value1 = MAROON;
		matrix->data->color_value2 = YELLOW;
		matrix->data->color_value3 = PURPLE;
	}
	else if (keydata.key == MLX_KEY_2)
	{
		matrix->data->color_value1 = OLIVE;
		matrix->data->color_value2 = LIME;
		matrix->data->color_value3 = TEAL;
	}
	else if (keydata.key == MLX_KEY_3)
	{
		matrix->data->color_value1 = CYAN;
		matrix->data->color_value2 = MAGENTA;
		matrix->data->color_value3 = SILVER;
	}
	new_img_gen(matrix, 1);
}
