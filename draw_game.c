/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/26 17:30:31 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	draw_circle(t_game *game)
{
	int		i;
	int		j;
	int		distance;
	int		radius;

	radius = 3;
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			distance = (i - game->bob.coords.x) * (i - game->bob.coords.x) + (j - game->bob.coords.y) * (j - game->bob.coords.y);
			if (distance <= radius * radius)
				my_mlx_pixel_put(game, i, j, RED);
			j++;
		}
		i++;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	draw_line(t_game *game, t_coords a, t_coords b)
{
	int			i;
	float		x;
	float		y;
	t_line		line;

	i = 0;
	x = a.x;
	y = a.y;
	line.dx = b.x - a.x;
	line.dy = b.y - a.y;
	line.m = line.dy / line.dx;
	line.steps = max(abs((int)line.dx), abs((int)line.dy));
	line.x_inc = line.dx / line.steps;
	line.y_inc = line.dy / line.steps;
	while (i < line.steps)
	{
		my_mlx_pixel_put(game, round(x), round(y), RED);
		// printf("[%.2f][%.2f]\n", x, y);
		x += line.x_inc;
		y += line.y_inc;
		i++;
	}
}

void	draw_square(t_game *game, int x, int y, int color)
{
	int		X;
	int		Y;

	Y = y + 1;
	while (Y < y + TILE_SIZE)
	{
		X = x + 1;
		while (X < x + TILE_SIZE)
		{
			my_mlx_pixel_put(game, X, Y, color);
			X++;
		}
		Y++;
	}
}

void	draw_map(t_game *game)
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
