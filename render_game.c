/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/05 16:09:53 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

t_coords	getline_coords(t_game *game)
{
	t_coords	endpoint;

	endpoint.x = 30 * cos(game->bob.rotationAngle) + game->bob.coords.x;
	endpoint.y = 30 * sin(game->bob.rotationAngle) + game->bob.coords.y;
	return (endpoint);
}

void	render_player(t_game *game)
{
	// draw_circle(game);
	// draw_line(game, game->bob.coords, getline_coords(game), RED);
	printf("(x: %d, y: %d)\n",game->bob.coords.x, game->bob.coords.y);
	printf("%f\n", game->bob.rotationAngle * (180 / M_PI));
}

void	render_crosshair(t_game *game)
{
	t_coords crosshair;
	
	crosshair.x = (WINDOW_WIDTH / 2) - 1;
	crosshair.y = (WINDOW_HEIGHT / 2) - 8;
	draw_rect(game, crosshair, 2, 6, 0x4EE41E);
	crosshair.x = (WINDOW_WIDTH / 2) - 10;
	crosshair.y = (WINDOW_HEIGHT / 2) - 1;
	draw_rect(game, crosshair, 8, 2, 0x4EE41E);
	crosshair.x = (WINDOW_WIDTH / 2) + 2;
	crosshair.y = (WINDOW_HEIGHT / 2) - 1;
	draw_rect(game, crosshair, 8, 2, 0x4EE41E);
	crosshair.x = (WINDOW_WIDTH / 2) - 1;
	crosshair.y = (WINDOW_HEIGHT / 2) + 1;
	draw_rect(game, crosshair, 2, 6, 0x4EE41E);
}

int	render_game(t_game	*game)
{
	update(game);
	render_walls(game);
	render_crosshair(game);
	minimap(game);
	// render_player(game);
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
	return (0);
}
