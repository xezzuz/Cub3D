/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 12:56:13 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	mousemove(int x, int y, t_game *game)
{
	(void)y;

	if (x > (WINDOW_WIDTH / 2) + 1) {
		game->bob.turnDirection = 1;
	}
	else if (x < (WINDOW_WIDTH / 2) - 1) {
		game->bob.turnDirection = -1;
	}
	else
		game->bob.turnDirection = 0;
	mlx_mouse_move(game->data.win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (0);
}
