/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:34:49 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/04 15:04:47 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	find_player(char **map)
{
	t_pos	pos;
	size_t	line;
	size_t	col;

	line = 0;
	while (map[line])
	{
		col = 0;
		while (map[line][col])
		{
			if (map[line][col] == 'P')
			{
				pos.line = line;
				pos.col = col;
			}
			col++;
		}
		line++;
	}
	return (pos);
}
