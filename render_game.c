/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/05 16:16:45 by nazouz           ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			if (i < WINDOW_HEIGHT / 2)
				my_mlx_pixel_put(game, j, i, 0x646661);
			else
				my_mlx_pixel_put(game, j, i, 0xBFC4B5);
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

void	render_minimap(t_game *game)
{
	t_coords		diff;
	t_coords		center;
	int				x;
	int				y;
	
	center.x = 150;
	center.y = 150;
	diff.x = center.x - game->bob.coords.x;
	diff.y = center.y - game->bob.coords.y;
	draw_rect(game, (t_coords){7,17}, 300, 300, 0x404040);
	draw_rect(game, (t_coords){12,12}, 300, 300, 0x606060);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (game->map[y / TILE_SIZE][x / TILE_SIZE] == '0')
			{
				if (x + diff.x <= 300 && x + diff.x >= 0 && y + diff.y <= 300 && y + diff.y >= 0)
					my_mlx_pixel_put(game, x + diff.x + 12, y + diff.y + 12, WHITE);
			}
			y++;
		}
		x++;
	}
	draw_rect(game, (t_coords){162,162}, 5, 5, RED);
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
	render_ceiling_floor(game);
	render_walls(game);
	render_crosshair(game);
	render_minimap(game);
	// render_player(game);
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
	return (0);
}
