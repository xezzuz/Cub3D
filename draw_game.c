/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/30 18:21:59 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	draw_circle(t_game *game)
{
	int	i;
	int	j;
	int	distance;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			distance = (i - game->bob.coords.x) * (i - game->bob.coords.x) + (j - game->bob.coords.y) * (j - game->bob.coords.y);
			if (distance <= game->bob.radius * game->bob.radius)
				my_mlx_pixel_put(game, i, j, 0x00FF0000);
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

void	draw_line(t_game *game, t_coords a, t_coords b, int color)
{
	int			i;
	float		x;
	float		y;
	t_line		line;
	int 		xx;
	int 		yy;

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
		xx = round(x);
		yy = round(y);
		if (game->map[yy / TILE_SIZE][xx / TILE_SIZE] == '1')
			break ;
		my_mlx_pixel_put(game, xx, yy, color);
		x += line.x_inc;
		y += line.y_inc;
		i++;
	}
}

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
