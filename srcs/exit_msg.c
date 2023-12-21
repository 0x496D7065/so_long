/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:45:55 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/03 13:39:32 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	return ;
}

void	exit_msg(char *msg, char **map)
{
	write(2, msg, ft_strlen(msg));
	if (map != NULL)
		ft_free_all_tab(map);
	exit(1);
}
