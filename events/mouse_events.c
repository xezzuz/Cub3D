/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 17:27:55 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;

	if (x > (WINDOW_WIDTH / 2))
		game->mouse_angle = 0.0255;
	else if (x < (WINDOW_WIDTH / 2))
		game->mouse_angle = -0.0255;
	mlx_mouse_move(game->data.win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	return (0);
}