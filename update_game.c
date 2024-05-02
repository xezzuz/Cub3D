/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:00:46 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/02 16:14:24 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int	difference(a, b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

double	ray_length(t_coords p, int rx, int ry)
{
	double		length;

	length = sqrt(((rx - p.x) * (rx - p.x)) + ((ry - p.y) * (ry - p.y)));
	return (length);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
t_coords	draw_line(t_game *game, t_coords a, t_coords b)
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
		// my_mlx_pixel_put(game, xx, yy, color);
		x += x_inc;
		y += y_inc;
		i++;
	}
	return (b);
}

// t_coords	get_rayend(t_game *game, t_coords endpoint)
// {
// 	t_line	line;

// 	line.stepx = difference(game->bob.coords.x, endpoint.x);
// 	line.stepy = difference(game->bob.coords.y, endpoint.y);
// 	line.intersection.x = game->bob.coords.x;
// 	line.intersection.y = game->bob.coords.y;
// 	line.dx = abs(endpoint.x - game->bob.coords.x);
// 	line.dy = abs(endpoint.y - game->bob.coords.y);
// 	while (line.intersection.x != endpoint.x && line.intersection.y != endpoint.y)
// 	{
//         if (game->map[line.intersection.y / TILE_SIZE][line.intersection.x / TILE_SIZE] == '1')
//             return (line.intersection);
//         line.e2 = 2 * line.err;
//         if (line.e2 > -line.dy)
// 		{
//             line.err -= line.dy;
//             line.intersection.x += line.stepx;
//         }
//         if (line.e2 < line.dx)
// 		{
//             line.err += line.dx;
//             line.intersection.y += line.stepy;
//         }
//     }
// 	return (endpoint);
// }

void	print_rays(t_game *game)
{
	int i;

	i = 0;
	while (i < 1920)
	{
		printf("@@@@@X(%d),Y(%d),DISTANCE(%f)\n",game->rays[i].endpoint.x, game->rays[i].endpoint.y, game->rays[i].distance);
		i++;
	}
}

void	cast_rays(t_game *game)
{
	double		current_angle;
	int			deltax;
	int			deltay;
	int			i;

	i = 0;
	current_angle = game->bob.rotationAngle - ((FOV) / 2);
	while (i < NUM_OF_RAYS)
	{
		game->rays[i].endpoint.x = game->bob.coords.x + (cos(current_angle) * 2000);
		game->rays[i].endpoint.y = game->bob.coords.y + (sin(current_angle) * 2000);
		game->rays[i].endpoint = draw_line(game, game->bob.coords, game->rays[i].endpoint);
		deltax = game->rays[i].endpoint.x - game->bob.coords.x;
		deltay = game->rays[i].endpoint.y - game->bob.coords.y;
		game->rays[i].distance = round(sqrt(deltax * deltax + deltay * deltay));
		current_angle += ((FOV) / (SCREEN_WIDTH / WALL_COL_WIDTH));
		// printf("X(%d),Y(%d),DISTANCE(%f)\n",game->rays[i].endpoint.x, game->rays[i].endpoint.y, game->rays[i].distance);
		i++;
	}
	print_rays(game);
}

void	update_player(t_game *game)
{
	float	moveStep;
	int		new_x;
	int		new_y;

	game->bob.rotationAngle += game->bob.turnDirection * game->bob.rotationSpeed;
	moveStep = game->bob.walkDirection * game->bob.moveSpeed;
	new_x = game->bob.coords.x + round(cos(game->bob.rotationAngle) * moveStep);
	new_y = game->bob.coords.y + round(sin(game->bob.rotationAngle) * moveStep);
	game->mapos.x -= round(cos(game->bob.rotationAngle) * moveStep);
	game->mapos.y -= round(sin(game->bob.rotationAngle) * moveStep);
	if (game->map[new_y / TILE_SIZE][new_x / TILE_SIZE] != '1')
	{
		game->bob.coords.x = new_x;
		game->bob.coords.y = new_y;
	}
}

// updates player position, rotation angle, etc...
void	update(t_game *game)
{
	update_player(game);
	cast_rays(game);
}
