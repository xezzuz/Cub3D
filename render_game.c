/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/01 15:49:50 by nazouz           ###   ########.fr       */
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

void	render_ceiling_floor(t_game *game)
{
	int			i;
	int			j;
	t_coords	pos;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			pos.x = j * TILE_SIZE;
			pos.y = i * TILE_SIZE;
			if (pos.y < HEIGHT / 2)
				draw_rect(game, pos, TILE_SIZE, TILE_SIZE, 0x646661);
			else
				draw_rect(game, pos, TILE_SIZE, TILE_SIZE, 0xBFC4B5);
			// my_mlx_pixel_put(game, pos.x, pos.y, WHITE);
			// if (game->map[i][j] == '1')
			// 	draw_rect(game, pos, TILE_SIZE, TILE_SIZE, BLACK);
			// else
			// 	draw_rect(game, pos, TILE_SIZE, TILE_SIZE,  WHITE);
			j++;
		}
		i++;
	}
}

void	render_player(t_game *game)
{
	// draw_circle(game);
	// draw_line(game, game->bob.coords, getline_coords(game), RED);
	printf("(x: %d, y: %d)\n",game->bob.coords.x, game->bob.coords.y);
	printf("%f\n", game->bob.rotationAngle * (180 / M_PI));
}

void	render_game(t_game	*game)
{
	update(game);
	render_ceiling_floor(game);
	render_fov(game);
	render_player(game);
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
}
