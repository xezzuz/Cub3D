/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/26 17:31:23 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

t_coords	getline_coords(t_game *game)
{
	t_coords	endpoint;
	double		delta;
	
	delta = game->bob.rotationAngle;
	endpoint.x = 20 * cos(delta) + game->bob.coords.x;
	endpoint.y = 20 * sin(delta) + game->bob.coords.y;
	printf("(x%d, y%d)\n", endpoint.x - game->bob.coords.x, endpoint.y - game->bob.coords.y);
	printf("%f\n", game->bob.rotationAngle * (180 / M_PI));
	return (endpoint);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == '1')
				draw_square(game, j * TILE_SIZE, i * TILE_SIZE, BLACK);
			else
				draw_square(game, j * TILE_SIZE, i * TILE_SIZE, WHITE);
			j++;
		}
		i++;
	}
}

void	render_player(t_game *game)
{
	draw_circle(game);
	draw_line(game, game->bob.coords, getline_coords(game));
}

void	render_game(t_game	*game)
{
	printf("BOB [%d, %d]\n", game->bob.coords.x, game->bob.coords.y);
	update_game(game);
	render_map(game);
	render_player(game);
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
}
