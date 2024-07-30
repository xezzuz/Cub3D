/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:18:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 18:57:44 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

// void	flip_door(t_game *game)
// {
// 	int x;
// 	int y;
// 	int	i;

// 	x = (game->rays[NUM_OF_RAYS / 2].endpoint.x);
// 	y = (game->rays[NUM_OF_RAYS / 2].endpoint.y);
// 	if (game->lvl.map[y / TILE][x / TILE] == 'D' && game->rays[NUM_OF_RAYS / 2].dis < 100)
// 	{
// 		i = 0;
// 		while (game->lvl.doors[i].coords.x != x / TILE)
// 			i++;
// 		printf("ss\n");
// 		if (game->lvl.doors[i].closed)
// 			game->lvl.doors[i].closed = 0;
// 		else
// 			game->lvl.doors[i].closed = 1;
// 	}
// }

void	flip_door(t_game *game)
{
	int x;
	int y;
	int	i;

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
	else if (key == ESC)
		exit_cub3d(game);
	// else if (key == SPACE && game->counter == 0)
	// 	game->animate = 1;
	// ESC KEY
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
