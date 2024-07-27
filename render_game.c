/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 12:10:42 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	render_game(t_game	*game)
{
	if (game->mouse_hide > 0)
		mlx_mouse_show();
	else
		mlx_mouse_hide();
	update_game(game);
	render_walls(game);
	render_minimap(game);
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.frame.img, 0, 0);



	// EXTRA STUFF
		// render_crosshair(game);
		// render_player(game);
		// if (game->animate == 1)
		// 	render_gun(game);
		// else
		// 	mlx_put_image_to_window(game->data.mlx, game->data.win, game->gun.frame1, 1100, 610);
	return (0);
}
