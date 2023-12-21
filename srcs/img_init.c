/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:23:17 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/04 15:33:41 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data **data)
{
	int	x;
	int	y;

	(*data)->img[0] = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"assets/player.xpm", &x, &y);
	(*data)->img[1] = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"assets/exit.xpm", &x, &y);
	(*data)->img[2] = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"assets/collectible.xpm", &x, &y);
	(*data)->img[3] = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"assets/wall.xpm", &x, &y);
	(*data)->img[4] = mlx_xpm_file_to_image((*data)->mlx_ptr,
			"assets/ground.xpm", &x, &y);
	if (!(*data)->img[0] || !(*data)->img[1] || !(*data)->img[2]
		|| !(*data)->img[3] || !(*data)->img[4])
		on_destroy(*data);
}

void	put_ground(t_data *data, size_t *line, size_t *col)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[4], (*col) * 40, (*line) * 40);
}
