/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:18:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 16:25:43 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	flip_door(t_game *game)
{
	int		i;
	int		x;
	int		y;

	x = game->bob.coords.x / TILE;
	y = game->bob.coords.y / TILE;
	i = 0;
	while (i < game->lvl.dcount)
	{
		if ((game->lvl.doors[i].coords.x - 1 == x
				&& game->lvl.doors[i].coords.y == y)
			|| (game->lvl.doors[i].coords.x + 1 == x
				&& game->lvl.doors[i].coords.y == y)
			|| (game->lvl.doors[i].coords.y + 1 == y
				&& game->lvl.doors[i].coords.x == x)
			|| (game->lvl.doors[i].coords.y - 1 == y
				&& game->lvl.doors[i].coords.x == x))
			game->lvl.doors[i].closed = !game->lvl.doors[i].closed;
		i++;
	}
}

int	keypress(int key, t_game *game)
{
	if (key == W)
		game->bob.upright = 1;
	else if (key == D)
		game->bob.sideways = -1;
	else if (key == A)
		game->bob.sideways = 1;
	else if (key == S)
		game->bob.upright = -1;
	else if (key == LEFT)
		game->bob.turn_dir = -1;
	else if (key == RIGHT)
		game->bob.turn_dir = 1;
	else if (key == SPACE)
		flip_door(game);
	else if (key == X)
		game->mouse_hidden = !game->mouse_hidden;
	else if (key == ESC)
		exit_cub3d(game);
	return (0);
}

int	keyrelease(int key, t_game *game)
{
	if (key == W)
		game->bob.upright = 0;
	else if (key == D)
		game->bob.sideways = 0;
	else if (key == A)
		game->bob.sideways = 0;
	else if (key == S)
		game->bob.upright = 0;
	else if (key == LEFT)
		game->bob.turn_dir = 0;
	else if (key == RIGHT)
		game->bob.turn_dir = 0;
	return (0);
}
