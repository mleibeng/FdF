/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:00:54 by mleibeng          #+#    #+#             */
/*   Updated: 2024/01/10 23:27:11 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "color_bonus.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_W	2304
# define MAX_H	1530

# define MAP_X_POS 960
# define MAP_Y_POS 640

typedef uint32_t	t_color;

typedef struct s_data
{
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			z;
	int			z1;
	int			zoom;
	int			x_pos;
	int			y_pos;
	int			x_offset;
	int			y_offset;
	t_color		color_value1;
	t_color		color_value2;
	t_color		color_value3;
	bool		view_angle;
	float		height;
}				t_data;

typedef struct s_matrix
{
	int			cols;
	int			rows;
	int			x_iter;
	int			y_iter;
	int			x_diff;
	int			y_diff;
	int			**map;
	float		cos_angle;
	float		sin_angle;

	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		*data;

}				t_matrix;

int			main(int argc, char **argv);
void		get_values(t_matrix *matrix, char *file);
void		draw_lines(t_matrix *matrix);
void		algorithm(float x1, float y1, t_matrix *matrix);
void		change_height_calc(float x1, float y1, t_matrix *matrix);
void		apply_zoom(float *x1, float *y1, t_matrix *matrix);
void		calc_dimension(float *dx, float *dy, t_matrix *matrix);
void		calc_diff(float *x1, float *y1, t_matrix *matrix);

/*----------Color functions--------------*/
t_color		check_color_value(t_matrix *matrix);
void		change_color_set(mlx_key_data_t keydata, t_matrix *matrix);

/*----------Change image-----------------*/
void		change_angle(float *x, float *y, int z, t_matrix *matrix);
void		next_coords(float *x, float dx, float *y, float dy);
void		move_map(float *x1, float *y1, t_matrix *matrix);
float		compare_func(float dx, float dy);
void		fill_map(int **map, char *file);
void		fill_values(int *height, char *value);
void		change_angle_func(float *x1, float *y1, t_matrix *matrix);
void		change_height_calc(float x1, float y1, t_matrix *matrix);
void		new_img_gen(t_matrix *matrix, bool new);

/*-----------------Bonus Key commands-----------------*/
void		change_view(mlx_key_data_t keydata, t_matrix *matrix);
void		movement_commands(mlx_key_data_t keydata, t_matrix *matrix);
void		change_scalability(mlx_key_data_t keydata, t_matrix *matrix);
void		change_height(mlx_key_data_t keydata, t_matrix *matrix);
void		scroll_func(double xdelta, double ydelta, void *param);

#endif