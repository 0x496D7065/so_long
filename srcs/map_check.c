/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:23:54 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/21 17:58:39 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_items	item_check(char **map, t_items items)
{
	size_t	line;
	size_t	i;

	line = 0;
	while (map[line])
	{
		i = 0;
		while (map[line][i])
		{
			if (!is_valid_item(map[line][i]))
				exit_msg(ERR_INVALID_ITEMS, map);
			if (map[line][i] == 'P')
				items.player++;
			if (map[line][i] == 'E')
				items.exit++;
			if (map[line][i] == 'C')
				items.maxc++;
			i++;
		}
		line++;
	}
	return (items);
}

void	is_closed(char **map)
{
	size_t	end;
	size_t	line;
	size_t	line_count;
	size_t	i;

	line = 1;
	line_count = 0;
	i = 0;
	end = ft_strlen(map[line]) - 1;
	while (map[line_count])
		line_count++;
	while (map[0][i])
		if (map[0][i++] != '1')
			exit_msg(ERR_NOT_CLOSED, map);
	while (map[line] && line < line_count)
	{
		if (map[line][0] != '1' || map[line][end] != '1')
			exit_msg(ERR_NOT_CLOSED, map);
		line++;
	}
	i = 0;
	while (map[line - 1][i])
		if (map[line - 1][i++] != '1')
			exit_msg(ERR_NOT_CLOSED, map);
}

void	is_rectangle(char **map)
{
	size_t	len;
	size_t	line;

	line = 0;
	len = ft_strlen(map[line]);
	while (map[line])
	{
		if (ft_strlen(map[line]) != len)
			exit_msg(ERR_NOT_RECTANGLE, map);
		line++;
	}
}

void	all_check(char	**map, t_data *data)
{
	t_items	items;
	t_pos	pos;
	int		res;

	items.maxc = 0;
	items.player = 0;
	items.exit = 0;
	is_rectangle(map);
	is_closed(map);
	items = item_check(map, items);
	items.cfound = 0;
	data->items = items;
	if (items.player != 1 || items.exit != 1 || items.maxc < 1)
		exit_msg(ERR_INVALID_ITEMS, map);
	items.exit = 0;
	pos = find_player(map);
	res = is_map_possible(map, pos.line, pos.col, &items);
	if (res == 0)
		exit_msg(ERR_NOT_POSSIBLE, map);
}

void	map_check(char *file, t_data *data)
{
	char	line_read[2001];
	char	**map;
	int		n;
	int		fd;

	fd = open(file, O_RDONLY);
	n = read(fd, line_read, 2000);
	if (n <= 0)
		exit_msg(ERR_READ_ERR, NULL);
	line_read[n] = '\0';
	map = ft_split(line_read, '\n');
	if (!map)
		exit_msg(ERR_MAP_ALLOC, NULL);
	all_check(map, data);
	ft_free_all_tab(map);
	map = ft_split(line_read, '\n');
	data->map = map;
	return ;
}
