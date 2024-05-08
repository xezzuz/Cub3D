/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:00:46 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/08 16:26:25 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

t_coords	cast_ray(t_game *game, t_coords a, t_coords b)
{
	int			i;
	float		x;
	float		y;
	t_coords	k;
	float		dx;
	float		dy;
	float		m;
	float		steps;
	float		x_inc;
	float		y_inc;

	i = 0;
	x = a.x;
	y = a.y;
	dx = b.x - a.x;
	dy = b.y - a.y;
	m = dy / dx;
	steps = max(abs((int)dx), abs((int)dy));
	x_inc = dx / steps;
	y_inc = dy / steps;
	while (i < steps)
	{
		k.x = round(x);
		k.y = round(y);
		if (game->map[k.y / TILE_SIZE][k.x / TILE_SIZE] == '1')
			return (k);
		x += x_inc;
		y += y_inc;
		i++;
	}
	return (b);
}

void	cast_rays(t_game *game)
{
	double		current_angle;
	double		deltax;
	double		deltay;
	int			i;

	i = 0;
	current_angle = game->bob.rotationAngle - ((FOV) / 2);
	while (i < NUM_OF_RAYS)
	{
		game->rays[i].endpoint.x = game->bob.coords.x + round(cos(current_angle) * TILE_SIZE * COLS * 2);
		game->rays[i].endpoint.y = game->bob.coords.y + round(sin(current_angle) * TILE_SIZE * COLS * 2);
		game->rays[i].endpoint = cast_ray(game, game->bob.coords, game->rays[i].endpoint);
		// if (i == (NUM_OF_RAYS / 2) - 1)
		// 	printf("x:%d,y:%d\n",game->rays[i].endpoint.x, game->rays[i].endpoint.y);
		deltax = game->rays[i].endpoint.x - game->bob.coords.x;
		deltay = game->rays[i].endpoint.y - game->bob.coords.y;
		game->rays[i].distance = sqrt(deltax * deltax + deltay * deltay) * cos(game->bob.rotationAngle - current_angle);
		current_angle += ((FOV) / (WINDOW_WIDTH / WALL_COL_WIDTH));
		i++;
	}
}

void	update_player(t_game *game)
{
	float	moveStep;
	float	diagmovestep;
	int		new_x;
	int		new_y;

	game->bob.rotationAngle += game->bob.turnDirection * game->bob.rotationSpeed;
	moveStep = game->bob.upright * game->bob.moveSpeed;
	diagmovestep = game->bob.sideways * game->bob.moveSpeed / 2;
	new_x = round(cos(game->bob.rotationAngle - (M_PI / 2)) * diagmovestep);
	new_y = round(sin(game->bob.rotationAngle - (M_PI / 2)) * diagmovestep);
	new_x += round(game->bob.coords.x + (cos(game->bob.rotationAngle) * moveStep));
	new_y += round(game->bob.coords.y + (sin(game->bob.rotationAngle) * moveStep));
	if (game->map[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1')
	{
		game->bob.coords.x = new_x;
		game->bob.coords.y = new_y;
	}
}

// updates player, cast rays...
void	update(t_game *game)
{
	update_player(game);
	cast_rays(game);
}
