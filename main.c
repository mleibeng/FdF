/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:39:07 by mleibeng          #+#    #+#             */
/*   Updated: 2024/01/11 18:22:03 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_func(t_matrix *matrix)
{
	int	i;

	i = 0;
	if (matrix->map)
	{
		while (matrix->map[i])
			free(matrix->map[i++]);
		free(matrix->map);
	}
	free(matrix);
}

void	key_func(mlx_key_data_t keydata, void *param)
{
	t_matrix	*matrix;
	keys_t		key;

	matrix = param;
	key = keydata.key;
	if (key == MLX_KEY_ESCAPE)
		mlx_close_window(matrix->mlx);
}

void	matrix_init(t_matrix *matrix, char *file, char *window, t_data *data)
{
	get_values(matrix, file);
	matrix->mlx = mlx_init(WIDTH - 100, HEIGHT - 50, window, true);
	if (!matrix->mlx)
		free_func(matrix);
	matrix->img = mlx_new_image(matrix->mlx, WIDTH * 1.2, HEIGHT * 1.5);
	matrix->sin_angle = 0.8;
	matrix->cos_angle = 0.8;
	matrix->data = data;
	if (matrix->cols > 100)
		matrix->data->zoom = 1;
	else if (matrix->cols > 10 && matrix->cols < 100)
		matrix->data->zoom = 20;
	else
		matrix->data->zoom = 40;
	matrix->data->view_angle = 1;
	matrix->data->x_pos = MAP_X_POS;
	matrix->data->y_pos = MAP_Y_POS;
	matrix->data->x_offset = -70;
	matrix->data->y_offset = -70;
	matrix->data->color_value1 = WHITE;
	matrix->data->color_value2 = RED;
	matrix->data->color_value3 = BLUE;
	matrix->data->height = 1.0;
}

int	main(int argc, char **argv)
{
	t_matrix	*matrix;
	t_data		data;

	if (argc != 2)
	{
		perror("Wrong amount of arguments");
		exit(EXIT_FAILURE);
	}
	matrix = malloc(sizeof(t_matrix));
	matrix_init(matrix, argv[1], "FDF", &data);
	draw_lines(matrix);
	mlx_image_to_window(matrix->mlx, matrix->img,
		matrix->data->x_offset, matrix->data->y_offset);
	mlx_key_hook(matrix->mlx, &key_func, matrix);
	mlx_loop(matrix->mlx);
	mlx_terminate(matrix->mlx);
	free_func(matrix);
	system("leaks FdF");
	return (EXIT_SUCCESS);
}
