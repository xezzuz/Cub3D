/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:18:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 12:17:58 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int keypress(int key, t_game *game)
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
		game->bob.turnDirection = -1;
	else if (key == RIGHT)
		game->bob.turnDirection = 1;
	else if (key == MOUSE)
		game->mouse_hide *= -1;
	else if (key == 49 && game->counter == 0)
		game->animate = 1;
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
		game->bob.turnDirection = 0;
	else if (key == RIGHT)
		game->bob.turnDirection = 0;
	return (0);
}
