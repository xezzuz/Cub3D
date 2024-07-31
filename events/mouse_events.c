/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:09:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 15:31:29 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (x != (WIN_WIDTH / 2))
		game->mouse_angle = -((WIN_WIDTH / 2) - x) * 0.001;
	mlx_mouse_move(game->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
