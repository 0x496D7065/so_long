/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:48:52 by lpetit            #+#    #+#             */
/*   Updated: 2023/12/21 17:51:01 by lpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	over_exit(t_data **data, size_t line, size_t col)
{
	put_exit(*data, &line, &col);
	(*data)->map[line][col] = 'E';
	(*data)->on_exit = 0;
}
