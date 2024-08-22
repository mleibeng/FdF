/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:39:52 by mleibeng          #+#    #+#             */
/*   Updated: 2024/01/10 22:11:00 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  ------------------------------- resources --------------------------------
**	--------------- 3D ------------------------------------------
**		x` = (x - y) * cos(angle);
**		y` = (x + y) * sin(angle) - z;
**	-------------------------------------------------------------
** 	------- mlx_function ----------------------------------------
**		void *mlx_ptr;
**		void *win_prt;
**
**		mlx_ptr = mlx_init();
**		win_prt = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
**
**		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);
**
**		mlx_key_hook(win_ptr, deal_key, NULL);
**		mlx_loop(mlx_ptr);
**	--------------------------------------------------------------
**	------- deal_key prototype -----------------------------------
**		int		deal_key(int key, void *data);
**	--------------------------------------------------------------
**	colors:
**		white = 0xffffff
**		red = 0xe80c0c
**	----------------------------
**	frameworks:
**		-framework OpenGL -framework AppKit
*/

#include "fdf_bonus.h"

// int get_rgba(int r, int g, int b, int a)
// {
// 	return (r << 24 | g << 16 | b << 8 | a);
// }

// float	absol(float num)
// {
// 	if (num < 0)
// 		return (num * -1);
// 	return (num);
// }

void	fill_map(int **map, char *file)
{
	int		i;
	int		fd;
	char	*values;

	i = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		values = get_next_line(fd);
		if (!values)
			break ;
		fill_values(map[i], values);
		free(values);
		i++;
	}
	map[i] = NULL;
	close(fd);
}

void	draw_lines(t_matrix *matrix)
{
	float	x1;
	float	y1;

	matrix->y_iter = 0;
	while (matrix->y_iter < matrix->rows)
	{
		matrix->x_iter = 0;
		while (matrix->x_iter < matrix->cols)
		{
			x1 = matrix->x_iter;
			y1 = matrix->y_iter;
			if (matrix->x_iter < matrix->cols - 1)
				algorithm(x1 + 1, y1, matrix);
			if (matrix->y_iter < matrix->rows - 1)
				algorithm(x1, y1 + 1, matrix);
			matrix->x_iter++;
		}
		matrix->y_iter++;
	}
}

void	algorithm(float x1, float y1, t_matrix *matrix)
{
	float	dx;
	float	dy;

	change_height_calc(x1, y1, matrix);
	apply_zoom(&x1, &y1, matrix);
	if (matrix->data->view_angle == 1)
		change_angle_func(&x1, &y1, matrix);
	move_map(&x1, &y1, matrix);
	matrix->data->x1 = x1;
	matrix->data->y1 = y1;
	calc_dimension(&dx, &dy, matrix);
	calc_diff(&x1, &y1, matrix);
	while (matrix->x_diff || matrix->y_diff)
	{
		if (matrix->data->x >= 0 && matrix->data->x < MAX_W
			&& matrix->data->y >= 0 && matrix->data->y < MAX_H)
		{
			mlx_put_pixel(matrix->img, matrix->data->x,
				matrix->data->y, check_color_value(matrix));
		}
		next_coords(&matrix->data->x, dx, &matrix->data->y, dy);
		calc_diff(&x1, &y1, matrix);
	}
}

void	new_img_gen(t_matrix *matrix, bool new)
{
	if (new == true)
		mlx_delete_image(matrix->mlx, matrix->img);
	matrix->img = mlx_new_image(matrix->mlx, WIDTH * 1.2, HEIGHT * 1.5);
	mlx_image_to_window(matrix->mlx, matrix->img,
		matrix->data->x_offset, matrix->data->y_offset);
	draw_lines(matrix);
}
