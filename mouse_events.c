/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 13:11:43 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	mouse_move(int new_mouse_x, int new_mouse_y, t_game *game)
{
	int		deltax;
	(void)new_mouse_y;

	printf("Mouse[%d, %d]\n", new_mouse_x, new_mouse_y);
	deltax = new_mouse_x - game->last_mouse_pos_x;
	if (deltax < 0)
		game->bob.turnDirection = 1;
	else if (deltax >= 0) {
		game->bob.turnDirection = -1;
	}
	game->last_mouse_pos_x = new_mouse_x;
	mlx_mouse_move(game->data.win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (0);
}

int	mouse_hook(t_game *game)
{
	int		mouse_pos_x;
	int		mouse_pos_y;

	mlx_mouse_hide();
	mlx_mouse_get_pos(game->data.win, &mouse_pos_x, &mouse_pos_y);
	if (mouse_pos_x != game->last_mouse_pos_x)
		mouse_move(mouse_pos_x, mouse_pos_y, game);
	else
		game->bob.rotationAngle = 0;
	return (1);
}
