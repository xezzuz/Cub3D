/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/03 18:27:33 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	draw_rect(t_game *game, t_coords start, int width, int height, int color)
{
	int		cols;
	int		rows;

	rows = start.y;
	while (rows < start.y + height)
	{
		cols = start.x;
		while (cols < start.x + width)
		{
			my_mlx_pixel_put(game, cols, rows, color);
			cols++;
		}
		rows++;
	}
}

void	render_walls(t_game *game)
{
	t_coords	start;
	double		p_wall_height;
	double		dppp;
	int			i;

	dppp = ((WINDOW_WIDTH) / 2) / tan(30 * (M_PI / 180));
	start.x = 0;
	i = 0;
	while (i < NUM_OF_RAYS / WALL_COL_WIDTH)
	{
		p_wall_height = (TILE_SIZE * dppp) / game->rays[i].distance;
		if (p_wall_height > WINDOW_HEIGHT)
			p_wall_height = WINDOW_HEIGHT;
		start.y = ((WINDOW_HEIGHT) / 2) - ((int)p_wall_height / 2);
		draw_rect(game, start, WALL_COL_WIDTH, p_wall_height, 0xA0A597);
		start.x += WALL_COL_WIDTH;
		i++;
	}
}
