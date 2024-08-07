/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:22:50 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/05 16:28:38 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"
#include<stdio.h>
void	count_rows_cols(t_game *game)
{
	int	col_len;

	game->lvl.columns = ft_strlen(game->lvl.map[0]);
	game->lvl.rows = 0;
	while (game->lvl.map[game->lvl.rows])
	{
		col_len = ft_strlen(game->lvl.map[game->lvl.rows]);
		if (col_len > game->lvl.columns)
			game->lvl.columns = col_len;
		game->lvl.rows++;
	}
	printf("%d\n", game->lvl.rows);
	game->lvl.height = TILE * game->lvl.rows;
	game->lvl.width = TILE * game->lvl.columns;
}

int	map_is_rect(t_game *game)
{
	int			i;

	count_rows_cols(game);
	i = -1;
	while (game->lvl.map[++i])
	{
		if (ft_strlen(game->lvl.map[i]) != (size_t)game->lvl.columns)
			return (0);
	}
	return (1);
}
