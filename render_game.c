/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/25 15:27:23 by mmaila           ###   ########.fr       */
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
	draw_rect(game, (t_coords){7,312}, 300, 7, 0x62645F);
	draw_rect(game, (t_coords){7,19}, 5, 300, 0x62645F);
	draw_rect(game, (t_coords){12,12}, 300, 300, 0x2F312D);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (x + diff.x <= 300 && x + diff.x >= 0 && y + diff.y <= 300 && y + diff.y >= 0)
				if (game->map[y / TILE_SIZE][x / TILE_SIZE] == '0')
					my_mlx_pixel_put(game, x + diff.x + 12, y + diff.y + 12, WHITE);
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

void	render_gun(t_game *game)
{
	if (game->counter <= 3)
		game->currframe = game->gun.frame1;
	else if (game->counter <= 6 && game->counter > 3)
		game->currframe = game->gun.frame2;
	else if (game->counter <= 9 && game->counter > 6)
		game->currframe = game->gun.frame3;
	else if (game->counter <= 12 && game->counter > 9)
		game->currframe = game->gun.frame4;
	else if (game->counter <= 15 && game->counter > 12)
		game->currframe = game->gun.frame5;
	else if (game->counter <= 18 && game->counter > 15)
		game->currframe = game->gun.frame6;
	else if (game->counter <= 21 && game->counter > 18)
		game->currframe = game->gun.frame3;
	// else if (game->counter <= 21 && game->counter > 18)
	// 	game->currframe = game->gun.frame7;
	// else if (game->counter <= 24 && game->counter > 21)
	// 	game->currframe = game->gun.frame8;
	// else if (game->counter <= 27 && game->counter > 24)
	// 	game->currframe = game->gun.frame9;
	// else if (game->counter <= 30 && game->counter > 27)
	// 	game->currframe = game->gun.frame10;
	// else if (game->counter <= 33 && game->counter > 30)
	// 	game->currframe = game->gun.frame11;
	// else if (game->counter <= 36 && game->counter > 33)
	// 	game->currframe = game->gun.frame12;
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->currframe, 1100, 610);
	game->counter++;
	if (game->counter == 25)
	{
		game->animate = 0;
		game->counter = 0;
	}
}

int	render_game(t_game	*game)
{
	update(game);
	render_walls(game);
	// render_crosshair(game);
	render_minimap(game);
	// render_player(game);
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.frame.img, 0, 0);
	// if (game->animate == 1)
	// 	render_gun(game);
	// else
	// 	mlx_put_image_to_window(game->data.mlx, game->data.win, game->gun.frame1, 1100, 610);
	return (0);
}
