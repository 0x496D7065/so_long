/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:18:12 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/21 17:40:29 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_printf.h"
# include <errno.h>
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define ERR_NO_MAP "Error, no map given\n"
# define ERR_NOT_BER_FILE "The given map is not a ber file, map invalid\n"
# define ERR_MAP_ALLOC "Error when allocating map buffer\n"
# define ERR_READ_ERR "Error reading the map\n"
# define ERR_NOT_RECTANGLE "The map is not rectangle, map invalid\n"
# define ERR_NOT_CLOSED "The map is not closed, map invalid\n"
# define ERR_INVALID_ITEMS "Items requirement not fulfilled, map invalid\n"
# define ERR_NOT_POSSIBLE "The map is not possible, map invalid\n"
# define ERR_MLX "Error when initiating MLX\n"

typedef struct s_items
{
	size_t	maxc;
	size_t	exit;
	size_t	player;
	size_t	cfound;
}		t_items;

typedef struct s_pos
{
	size_t	line;
	size_t	col;
}	t_pos;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img[5];
	char	**map;
	int		count;
	int		on_exit;
	t_pos	pos;
	t_items	items;
}	t_data;

t_pos	find_player(char **map);

char	**ft_split(char const *s, char c);
void	map_check(char *file, t_data *data);
char	*ft_strdup(char const *s);

size_t	ft_strlen(char const *str);

int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		is_valid_item(char c);
int		is_map_possible(char **map, size_t line, size_t col, t_items *items);
int		check_moves(char **map, size_t line, size_t col, int i);
int		on_destroy(t_data *data);

void	ft_free_all_tab(char **tab);
void	image_to_window(t_data *data);
void	key_dispatch(t_data *data, int keysym);
void	put_image(t_data **data);
void	put_ground(t_data *data, size_t *line, size_t *col);
void	put_player(t_data *data, size_t *line, size_t *col);
void	put_exit(t_data *data, size_t *line, size_t *col);
void	over_exit(t_data **data, size_t line, size_t col);
void	exit_msg(char *msg, char **map);

#endif
