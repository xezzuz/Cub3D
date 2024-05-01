/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:00:46 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/01 15:46:35 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	update_player(t_game *game)
{
	float	moveStep;
	int		new_x;
	int		new_y;

	game->bob.rotationAngle += game->bob.turnDirection * game->bob.rotationSpeed;
	moveStep = game->bob.walkDirection * game->bob.moveSpeed;
	new_x = game->bob.coords.x + round(cos(game->bob.rotationAngle) * moveStep);
	new_y = game->bob.coords.y + round(sin(game->bob.rotationAngle) * moveStep);
	game->mapos.x -= round(cos(game->bob.rotationAngle) * moveStep);
	game->mapos.y -= round(sin(game->bob.rotationAngle) * moveStep);
	if (game->map[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1')
	{
		game->bob.coords.x = new_x;
		game->bob.coords.y = new_y;
	}
}
// updates player position, rotation angle, etc...
void	update(t_game *game)
{
	update_player(game);
}
