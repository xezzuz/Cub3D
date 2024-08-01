/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 16:10:57 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	mouse_adjustement(t_game *game)
{
	if (game->mouse_angle > 0 && game->mouse_angle < 0.5)
		game->mouse_angle -= 0.001;
	else if (game->mouse_angle > 0.5)
		game->mouse_angle -= 0.0013;
	else
		game->mouse_angle = 0;
	if (game->mouse_hidden == 1)
		mlx_mouse_hide();
	else if (game->mouse_hidden == 0)
		mlx_mouse_show();
}

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
