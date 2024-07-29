/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/29 18:44:46 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	render_game(t_game	*game)
{
	update_player(game);
	cast_rays(game);
	render_walls(game);
	render_minimap(game);
	game->mouse_angle = 0;
	mlx_mouse_hide();
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);



	// EXTRA STUFF
		// render_crosshair(game);
		// render_player(game);
		// if (game->animate == 1)
		// 	render_gun(game);
		// else
		// 	mlx_put_image_to_window(game->data.mlx, game->data.win, game->gun.frame1, 1100, 610);
	return (0);
}
