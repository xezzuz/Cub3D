/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 10:29:29 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	mousemove(int x, int y, t_game *game)
{
	(void)game;
	(void)y;
	// printf("last move[%d]\n", x);
	// printf("mouse[%d]\n", x);
	if (x < game->last_mouse_x - 2)
	{
		game->bob.turnDirection = -1;
		// printf("x[%d] < last[%d] => moving left\n", x, game->last_mouse_x);
	}
	else if (x > game->last_mouse_x + 2)
	{
		game->bob.turnDirection = 1;
		// printf("x[%d] > last[%d] => moving right\n", x, game->last_mouse_x);
	}
	else
	{
		game->bob.turnDirection = 0;
		// printf("x[%d] == last[%d] => stop moving\n", x, game->last_mouse_x);
	}
	game->last_mouse_x = x;
	return (0);
}
