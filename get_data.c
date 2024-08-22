/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 02:20:26 by mleibeng          #+#    #+#             */
/*   Updated: 2024/01/10 21:43:22 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	map_length(char *file)
{
	int		length;
	char	*value;
	int		fd;

	length = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		value = get_next_line(fd);
		if (!value)
			break ;
		length++;
		free(value);
	}
	close(fd);
	return (length);
}

int	map_width(char *file)
{
	int		width;
	char	*value;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	width = 0;
	value = get_next_line(fd);
	if (!value)
		return (-1);
	while (value[i])
	{
		while (value[i] == ' ' && value[i] != '\0')
			i++;
		if (value[i])
			width++;
		while (value[i] != ' ' && value[i] != '\0')
			i++;
	}
	close(fd);
	free(value);
	return (width);
}

int	error_check(t_matrix *matrix)
{
	int	i;

	i = 0;
	perror("Error in getting map data");
	if (matrix->map)
	{
		while (matrix->map[i])
			free(matrix->map[i++]);
		free(matrix->map);
	}
	free(matrix);
	exit(EXIT_FAILURE);
}

void	fill_values(int *height, char *value)
{
	char	**digits;
	int		i;

	digits = ft_split(value, ' ');
	i = 0;
	while (digits[i])
	{
		height[i] = ft_atoi(digits[i]);
		free(digits[i]);
		i++;
	}
	free(digits);
}

void	get_values(t_matrix *matrix, char *file)
{
	int	i;

	i = 0;
	matrix->cols = map_width(file);
	matrix->rows = map_length(file);
	if (matrix->cols == -1 || matrix->rows == -1)
		error_check(matrix);
	matrix->map = (int **)malloc(sizeof(int *) * (matrix->rows + 1));
	if (!matrix->map)
		error_check(matrix);
	while (i < matrix->rows)
		matrix->map[i++] = (int *)malloc(sizeof(int) * (matrix->cols + 1));
	if (!matrix->map[i - 1])
		error_check(matrix);
	fill_map(matrix->map, file);
}
