/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 16:48:48 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	render_game(t_game	*game)
{
	update_player(game);
	cast_rays(game);
	render_walls(game);
	render_minimap(game);
	if (game->mouse_angle > 0)
		game->mouse_angle -= 0.001;
	else if (game->mouse_angle > 0.5)
		game->mouse_angle -= 0.0013;
	else
		game->mouse_angle = 0;
	mlx_mouse_hide();
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	display_animation_frame(game);
	return (0);
}
