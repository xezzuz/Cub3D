/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/03 18:10:51 by nazouz           ###   ########.fr       */
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

// void	draw_line(t_game *game, int z, t_coords a, t_coords b, int color)
// {
// 	int			i;
// 	float		x;
// 	float		y;
// 	t_line		line;
// 	int 		xx;
// 	int 		yy;

// 	(void)color;
// 	i = 0;
// 	x = a.x;
// 	y = a.y;
// 	line.dx = b.x - a.x;
// 	line.dy = b.y - a.y;
// 	line.m = line.dy / line.dx;
// 	line.steps = max(abs((int)line.dx), abs((int)line.dy));
// 	line.x_inc = line.dx / line.steps;
// 	line.y_inc = line.dy / line.steps;
// 	while (i < line.steps)
// 	{
// 		xx = round(x);
// 		yy = round(y);
// 		if (game->map[yy / TILE_SIZE][xx / TILE_SIZE] == '1')
// 			break ;
// 		x += line.x_inc;
// 		y += line.y_inc;
// 		i++;
// 	}
// }

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
	// render_player(game);
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
	return (0);
}
