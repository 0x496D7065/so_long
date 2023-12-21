/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:57:06 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/04 16:03:54 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_item(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	else
		return (0);
}

int	check_moves(char **map, size_t line, size_t col, int i)
{
	if (map[line - 1][col] != '1' && i == 0)
		return (1);
	if (map[line + 1][col] != '1' && i == 1)
		return (1);
	if (map[line][col - 1] != '1' && i == 2)
		return (1);
	if (map[line][col + 1] != '1' && i == 3)
		return (1);
	return (0);
}

int	is_map_possible(char **map, size_t line, size_t col, t_items *items)
{
	if (map[line][col] == 'C')
		items->cfound++;
	if (map[line][col] == 'E')
		items->exit++;
	map[line][col] = '1';
	if (check_moves(map, line, col, 0))
		is_map_possible(map, line - 1, col, items);
	if (check_moves(map, line, col, 1))
		is_map_possible(map, line + 1, col, items);
	if (check_moves(map, line, col, 2))
		is_map_possible(map, line, col - 1, items);
	if (check_moves(map, line, col, 3))
		is_map_possible(map, line, col + 1, items);
	if (items->cfound == items->maxc && items->exit == 1)
		return (1);
	return (0);
}
