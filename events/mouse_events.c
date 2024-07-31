/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 16:28:32 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	if (!game->mouse_hidden)
		return (0);
	(void)y;
	if (x > WIN_WIDTH / 2)
		game->mouse_mp = 1;
	else if (x < WIN_WIDTH / 2)
		game->mouse_mp = -1;
	game->mouse_angle = fabs(((WIN_WIDTH / 2) - x) * 0.0005);
	mlx_mouse_move(game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
