/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:18:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 16:05:05 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
