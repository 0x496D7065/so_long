/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:04:15 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/04 15:30:45 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player(t_data *data, size_t *line, size_t *col)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[0], (*col) * 40, (*line) * 40);
}

void	put_exit(t_data *data, size_t *line, size_t *col)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[1], (*col) * 40, (*line) * 40);
}

void	put_collectible(t_data *data, size_t *line, size_t *col)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[2], (*col) * 40, (*line) * 40);
}

void	put_wall(t_data *data, size_t *line, size_t *col)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[3], (*col) * 40, (*line) * 40);
}

void	image_to_window(t_data *data)
{
	size_t	line;
	size_t	col;

	line = 0;
	col = 0;
	put_image(&data);
	while (data->map[line])
	{
		col = 0;
		while (data->map[line][col])
		{
			if (data->map[line][col] == 'P')
				put_player(data, &line, &col);
			if (data->map[line][col] == 'E')
				put_exit(data, &line, &col);
			if (data->map[line][col] == 'C')
				put_collectible(data, &line, &col);
			if (data->map[line][col] == '1')
				put_wall(data, &line, &col);
			if (data->map[line][col] == '0')
				put_ground(data, &line, &col);
			col++;
		}
		line++;
	}
}
