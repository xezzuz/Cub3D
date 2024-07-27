/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 11:38:33 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	mousemove(int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;

	// mlx_mouse_get_pos(game->data.win, &a, &b);
	mlx_mouse_move(game->data.win, WIDTH / 2, HEIGHT / 2);
	printf("Mouse Position [%d, %d]\n", x, y);
	if (x > WIDTH / 2) {
		game->bob.turnDirection = 1;
	}
	else if (x < WIDTH / 2) {
		game->bob.turnDirection = -1;
	}
	// mlx_mouse_move(game->data.win, WIDTH / 2, HEIGHT / 2);












	
	// printf("last move[%d]\n", x);
	// printf("mouse[%d]\n", x);
	// if (x < game->last_mouse_x - 2)
	// {
	// 	game->bob.turnDirection = -1;
	// 	// printf("x[%d] < last[%d] => moving left\n", x, game->last_mouse_x);
	// }
	// else if (x > game->last_mouse_x + 2)
	// {
	// 	game->bob.turnDirection = 1;
	// 	// printf("x[%d] > last[%d] => moving right\n", x, game->last_mouse_x);
	// }
	// else
	// {
	// 	game->bob.turnDirection = 0;
	// 	// printf("x[%d] == last[%d] => stop moving\n", x, game->last_mouse_x);
	// }
	// game->last_mouse_x = x;
	return (0);
}
