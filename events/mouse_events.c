/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 14:00:49 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (x > (WIN_WIDTH / 2))
		game->mouse_angle = 0.0255;
	else if (x < (WIN_WIDTH / 2))
		game->mouse_angle = -0.0255;
	mlx_mouse_move(game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
