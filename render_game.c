/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:56:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/26 18:53:22 by mmaila           ###   ########.fr       */
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
	printf("(x: %d, y: %d)\n",game->bob.coords.x, game->bob.coords.y);
	printf("%f\n", game->bob.rotationAngle * (180 / M_PI));
}

void	render_game(t_game	*game)
{
	update(game);
	render_map(game);
	render_player(game);
	mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
}
