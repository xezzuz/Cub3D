/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:00:46 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/26 17:57:01 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	update_player(t_game *game)
{
	double		moveStep;

	// player position based on turn direction and walk direction
	game->bob.rotationAngle += game->bob.turnDirection * game->bob.rotationSpeed;
	moveStep = game->bob.walkDirection * game->bob.moveSpeed;
	printf("%f\n", cos(game->bob.rotationAngle));
	printf("%f\n", sin(game->bob.rotationAngle));
	game->bob.coords.x += (cos(game->bob.rotationAngle) * moveStep);
	game->bob.coords.y += (sin(game->bob.rotationAngle) * moveStep);
	printf("(%d, %d)\n", game->bob.turnDirection, game->bob.walkDirection);
}

void	update_game(t_game *game)
{
	update_player(game);
}
