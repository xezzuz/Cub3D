/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:00:46 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/29 09:26:44 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	distance(t_coords a, t_fcoords b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

float	cycle(float ray_angle)
{
	float	angle;

	angle = fmod(ray_angle, 2.0 * M_PI);
	if (ray_angle < 0)
		angle += (2.0 * M_PI);
	return (angle);
}

int	wallhit(t_game *game, t_fcoords check)
{
	int x;
	int	y;

	x = floor(check.x);
	y = floor(check.y);
	if (game->map[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (1);
	return (0);
}

t_fcoords	horizontal(t_game *game, t_ray *ray)
{
	t_fcoords	intercept;
	t_fcoords	step;

	intercept.y = floor(game->bob.coords.y / TILE_SIZE) * TILE_SIZE;
	intercept.y += (ray->down * TILE_SIZE);
	intercept.x = game->bob.coords.x + ((intercept.y - game->bob.coords.y) / tan(ray->ray_angle));
	step.y = TILE_SIZE;
	step.y *= ray->up ? -1 : 1;
	step.x = TILE_SIZE / tan(ray->ray_angle);
	step.x *= (ray->left && step.x > 0) ? -1 : 1;
	step.x *= (ray->right && step.x < 0) ? -1 : 1;
	while (intercept.x >= 0 && intercept.x <= WIDTH && intercept.y >= 0 && intercept.y <= HEIGHT)
	{
		if (wallhit(game, (t_fcoords){intercept.x, intercept.y - ray->up}))
			return (intercept);
		intercept.x += step.x;
		intercept.y += step.y;
	}
	intercept.x = -1;
	return (intercept);
}

t_fcoords	vertical(t_game *game, t_ray *ray)
{
	t_fcoords	intercept;
	t_fcoords	step;

	intercept.x = floor(game->bob.coords.x / TILE_SIZE) * TILE_SIZE;
	intercept.x += (ray->right * TILE_SIZE);
	intercept.y = game->bob.coords.y + ((intercept.x - game->bob.coords.x) * tan(ray->ray_angle));
	step.x = TILE_SIZE;
	step.x *= ray->left ? -1 : 1;
	step.y = TILE_SIZE * tan(ray->ray_angle);
	step.y *= (ray->up && step.y > 0) ? -1 : 1;
	step.y *= (ray->down && step.y < 0) ? -1 : 1;
	while (intercept.x >= 0 && intercept.x <= WIDTH && intercept.y >= 0 && intercept.y <= HEIGHT)
	{
		if (wallhit(game, (t_fcoords){intercept.x - ray->left, intercept.y}))
			return (intercept);
		intercept.x += step.x;
		intercept.y += step.y;
	}
	intercept.x = -1;
	return (intercept);
}

void	calc_hit(t_game *game, t_ray *ray)
{
	t_fcoords	hintercept;
	t_fcoords	vintercept;
	float		hdistance;
	float		vdistance;

	vintercept = vertical(game, ray);
	hintercept = horizontal(game, ray);
	if (hintercept.x != -1)
		hdistance = distance(game->bob.coords, hintercept);
	else
		hdistance = __FLT_MAX__;
	if (vintercept.x != -1)
		vdistance = distance(game->bob.coords, vintercept);
	else
		vdistance = __FLT_MAX__;
	if (hdistance < vdistance)
	{
		ray->distance = hdistance;
		ray->endpoint = hintercept;
		ray->horizontal = 1;
	}
	else
	{
		ray->distance = vdistance;
		ray->endpoint = vintercept;
		ray->horizontal = 0;
	}
}

void	cast_rays(t_game *game)
{
	float		current_angle;
	int			i;

	i = 0;
	current_angle = game->bob.rot_angle - ((FOV) / 2);
	while (i < NUM_OF_RAYS)
	{
		current_angle = cycle(current_angle);
		game->rays[i].ray_angle = current_angle;
		game->rays[i].down = current_angle < M_PI;
		game->rays[i].up = !game->rays[i].down;
		game->rays[i].right = current_angle < M_PI_2 || current_angle > (1.5 * M_PI);
		game->rays[i].left = !game->rays[i].right;
		calc_hit(game, &game->rays[i]);
		game->rays[i].distance *= cos(game->rays[i].ray_angle - game->bob.rot_angle);
		game->rays[i].wall_height = (TILE_SIZE * game->bob.dppp) / game->rays[i].distance;
		current_angle += ((FOV) / NUM_OF_RAYS);
		i++;
	}
}

int	hitbox(t_game *game, int new_x, int new_y)
{
	game->bob.radius.up.y = new_y - 6;
	game->bob.radius.up.x = new_x;
	game->bob.radius.right.y = new_y;
	game->bob.radius.right.x = new_x + 6;
	game->bob.radius.left.y = new_y;
	game->bob.radius.left.x = new_x - 6;
	game->bob.radius.down.y = new_y + 6;
	game->bob.radius.down.x = new_x;
	if (game->map[game->bob.radius.up.y / TILE_SIZE][game->bob.radius.up.x / TILE_SIZE] == '1'
		|| game->map[game->bob.radius.right.y / TILE_SIZE][game->bob.radius.right.x / TILE_SIZE] == '1'
		|| game->map[game->bob.radius.left.y / TILE_SIZE][game->bob.radius.left.x / TILE_SIZE] == '1'
		|| game->map[game->bob.radius.down.y / TILE_SIZE][game->bob.radius.down.x / TILE_SIZE] == '1')
		return (1);
	return (0);
}

void	update_player(t_game *game)
{
	float	moveStep;
	float	diagmovestep;
	int		new_x;
	int		new_y;

	game->bob.rot_angle += game->bob.turnDirection * game->bob.rotationSpeed + game->mouse_angle;
	moveStep = game->bob.upright * game->bob.moveSpeed;
	diagmovestep = game->bob.sideways * game->bob.moveSpeed / 2;
	new_x = round(cos(game->bob.rot_angle - (M_PI / 2)) * diagmovestep);
	new_y = round(sin(game->bob.rot_angle - (M_PI / 2)) * diagmovestep);
	new_x += round(game->bob.coords.x + (cos(game->bob.rot_angle) * moveStep));
	new_y += round(game->bob.coords.y + (sin(game->bob.rot_angle) * moveStep));
	if (!hitbox(game, new_x, new_y))
	{
		game->bob.coords.x = new_x;
		game->bob.coords.y = new_y;
	}
}

// updates player, cast rays...
void	update_game(t_game *game)
{
	update_player(game);
	cast_rays(game);
}
