/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:00:46 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 14:04:43 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

float	distance(t_coords a, t_fcoords b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

float	cycle(float ray_angle)
{
	float	angle;

	angle = fmod(ray_angle, 2.0 * M_PI);
	if (angle < 0)
		angle += (2.0 * M_PI);
	return (angle);
}

void	cast_rays(t_game *game)
{
	float		curr_angle;
	int			i;

	i = 0;
	curr_angle = game->bob.rot_angle - ((FOV) / 2);
	while (i < NUM_OF_RAYS)
	{
		curr_angle = cycle(curr_angle);
		game->rays[i].doorh = 0;
		game->rays[i].doorv = 0;
		game->rays[i].door = 0;
		game->rays[i].angle = curr_angle;
		game->rays[i].down = curr_angle < M_PI;
		game->rays[i].right = curr_angle < M_PI_2 || curr_angle > (1.5 * M_PI);
		calc_hit(game, &game->rays[i]);
		game->rays[i].dis *= cos(game->rays[i].angle - game->bob.rot_angle);
		game->rays[i].wall_height = (TILE * game->bob.dppp)
			/ game->rays[i].dis;
		curr_angle += ((FOV) / NUM_OF_RAYS);
		i++;
	}
}

int	doorcheck(t_map *lvl, int x, int y)
{
	int	i;

	i = 0;
	if (lvl->map[y / TILE][x / TILE] != 'D')
		return (0);
	while (i < lvl->dcount)
	{
		if (lvl->doors[i].coords.x == x / TILE
			&& lvl->doors[i].coords.y == y / TILE)
			return (lvl->doors[i].closed);
		i++;
	}
	return (0);
}

int	hitbox(t_map *lvl, t_hitbox *box, int new_x, int new_y)
{
	box->up.y = new_y - 6;
	box->up.x = new_x;
	box->right.y = new_y;
	box->right.x = new_x + 6;
	box->left.y = new_y;
	box->left.x = new_x - 6;
	box->down.y = new_y + 6;
	box->down.x = new_x;
	if (lvl->map[box->up.y / TILE][box->up.x / TILE] == '1'
		|| doorcheck(lvl, box->up.x, box->up.y)
		|| lvl->map[box->right.y / TILE][box->right.x / TILE] == '1'
		|| doorcheck(lvl, box->right.x, box->right.y)
		|| lvl->map[box->left.y / TILE][box->left.x / TILE] == '1'
		|| doorcheck(lvl, box->left.x, box->left.y)
		|| lvl->map[box->down.y / TILE][box->down.x / TILE] == '1'
		|| doorcheck(lvl, box->down.x, box->down.y))
		return (1);
	return (0);
}

void	update_player(t_game *game)
{
	float	move_step;
	float	diagmovestep;
	int		new_x;
	int		new_y;

	game->bob.rot_angle += game->bob.turn_dir * game->bob.rot_speed;
	game->bob.rot_angle += game->mouse_angle;
	move_step = game->bob.upright * game->bob.move_speed;
	diagmovestep = game->bob.sideways * game->bob.move_speed / 2;
	new_x = round(cos(game->bob.rot_angle - (M_PI / 2)) * diagmovestep);
	new_y = round(sin(game->bob.rot_angle - (M_PI / 2)) * diagmovestep);
	new_x += round(game->bob.coords.x + (cos(game->bob.rot_angle) * move_step));
	new_y += round(game->bob.coords.y + (sin(game->bob.rot_angle) * move_step));
	if (!hitbox(&game->lvl, &game->bob.box, new_x, new_y))
	{
		game->bob.coords.x = new_x;
		game->bob.coords.y = new_y;
	}
}
