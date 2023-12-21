/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:44:29 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/21 18:11:40 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	win_size(char **map)
{
	t_pos	pos;
	size_t	line;
	size_t	col;

	line = 0;
	col = 0;
	while (map[line])
		line++;
	while (map[0][col])
		col++;
	pos.line = line;
	pos.col = col;
	return (pos);
}

int	on_destroy(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("Total =%d\n", data->count);
	while (i < 5)
	{
		if (data->img[i] != NULL)
			mlx_destroy_image(data->mlx_ptr, data->img[i]);
		i++;
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	ft_free_all_tab(data->map);
	system("leaks so_long.out");
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == 65307)
		on_destroy(data);
	data->pos = find_player(data->map);
	key_dispatch(data, keysym);
	return (0);
}

void	win_init(t_data data)
{
	t_pos	size;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		exit_msg(ERR_MLX, data.map);
	size = win_size(data.map);
	data.win_ptr = mlx_new_window(data.mlx_ptr, size.col * 40,
			size.line * 40, "so_long");
	if (!data.win_ptr)
	{
		free(data.mlx_ptr);
		exit_msg(ERR_MLX, data.map);
	}
	image_to_window(&data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify,
		StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		data.count = 0;
		data.on_exit = 0;
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
			exit_msg(ERR_NOT_BER_FILE, NULL);
		map_check(argv[1], &data);
		win_init(data);
		return (0);
	}
	exit_msg(ERR_NO_MAP, NULL);
}
