/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:24:08 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/21 18:00:45 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	move_up(t_data *data)
{
	size_t	line;
	size_t	col;

	line = data->pos.line;
	col = data->pos.col;
	if (data->map[line - 1][col] == 'C')
		data->items.cfound += 1;
	if (data->map[line - 1][col] == 'E' &&
		data->items.maxc == data->items.cfound)
		on_destroy(data);
	put_ground(data, &line, &col);
	data->map[line][col] = '0';
	if (data->on_exit == 1)
		over_exit(&data, line, col);
	if (data->map[line - 1][col] == 'E')
		data->on_exit = 1;
	line -= 1;
	put_player(data, &line, &col);
	data->map[line][col] = 'P';
	data->count += 1;
	ft_printf("move count = %d\n", data->count);
	return ;
}

void	move_down(t_data *data)
{
	size_t	line;
	size_t	col;

	line = data->pos.line;
	col = data->pos.col;
	if (data->map[line + 1][col] == 'C')
		data->items.cfound += 1;
	if (data->map[line + 1][col] == 'E' &&
		data->items.maxc == data->items.cfound)
		on_destroy(data);
	put_ground(data, &line, &col);
	data->map[line][col] = '0';
	if (data->on_exit == 1)
		over_exit(&data, line, col);
	if (data->map[line + 1][col] == 'E')
		data->on_exit = 1;
	line += 1;
	put_player(data, &line, &col);
	data->map[line][col] = 'P';
	data->count += 1;
	ft_printf("move count = %d\n", data->count);
	return ;
}

void	move_left(t_data *data)
{
	size_t	line;
	size_t	col;

	line = data->pos.line;
	col = data->pos.col;
	if (data->map[line][col - 1] == 'C')
		data->items.cfound += 1;
	if (data->map[line][col - 1] == 'E' &&
		data->items.maxc == data->items.cfound)
		on_destroy(data);
	put_ground(data, &line, &col);
	data->map[line][col] = '0';
	if (data->on_exit == 1)
		over_exit(&data, line, col);
	if (data->map[line][col - 1] == 'E')
		data->on_exit = 1;
	col -= 1;
	put_player(data, &line, &col);
	data->map[line][col] = 'P';
	data->count += 1;
	ft_printf("move count = %d\n", data->count);
	return ;
}

void	move_right(t_data *data)
{
	size_t	line;
	size_t	col;

	line = data->pos.line;
	col = data->pos.col;
	if (data->map[line][col + 1] == 'C')
		data->items.cfound += 1;
	if (data->map[line][col + 1] == 'E' &&
		data->items.maxc == data->items.cfound)
		on_destroy(data);
	put_ground(data, &line, &col);
	data->map[line][col] = '0';
	if (data->on_exit == 1)
		over_exit(&data, line, col);
	if (data->map[line][col + 1] == 'E')
		data->on_exit = 1;
	col += 1;
	put_player(data, &line, &col);
	data->map[line][col] = 'P';
	data->count += 1;
	ft_printf("move count = %d\n", data->count);
	return ;
}

void	key_dispatch(t_data *data, int keysym)
{
	size_t	line;
	size_t	col;

	line = data->pos.line;
	col = data->pos.col;
	if (keysym == 119 && data->map[line - 1][col] != '1')
		move_up(data);
	if (keysym == 115 && data->map[line + 1][col] != '1')
		move_down(data);
	if (keysym == 97 && data->map[line][col - 1] != '1')
		move_left(data);
	if (keysym == 100 && data->map[line][col + 1] != '1')
		move_right(data);
	return ;
}
