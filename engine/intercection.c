/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intercection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:40:02 by mmaila            #+#    #+#             */
/*   Updated: 2024/07/31 10:39:14 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	wallhit(t_game *game, t_fcoords check, int *door)
{
	int	x;
	int	y;

	x = floor(check.x);
	y = floor(check.y);
	if (game->lvl.map[y / TILE][x / TILE] == '1'
		|| game->lvl.map[y / TILE][x / TILE] == ' ')
		return (1);
	if (doorcheck(&game->lvl, x, y))
		return (*door = 1, 1);
	return (0);
}

t_fcoords	horiz(t_game *game, t_ray *ray)
{
	t_fcoords	intercept;
	t_fcoords	step;

	intercept.y = floor(game->bob.coords.y / TILE) * TILE;
	intercept.y += (ray->down * TILE);
	intercept.x = game->bob.coords.x
		+ (intercept.y - game->bob.coords.y) / tan(ray->angle);
	step.y = TILE;
	if (!ray->down)
		step.y *= -1;
	step.x = TILE / tan(ray->angle);
	if (!ray->right && step.x > 0)
		step.x *= -1;
	if (ray->right && step.x < 0)
		step.x *= -1;
	while (intercept.x >= 0 && intercept.x <= game->lvl.width
		&& intercept.y >= 0 && intercept.y <= game->lvl.height)
	{
		if (wallhit(game, (t_fcoords){intercept.x, intercept.y - !ray->down}, &ray->doorh))
			return (intercept);
		intercept.x += step.x;
		intercept.y += step.y;
	}
	intercept.x = -1;
	return (intercept);
}

t_fcoords	vert(t_game *game, t_ray *ray)
{
	t_fcoords	intercept;
	t_fcoords	step;

	intercept.x = floor(game->bob.coords.x / TILE) * TILE;
	intercept.x += (ray->right * TILE);
	intercept.y = game->bob.coords.y
		+ (intercept.x - game->bob.coords.x) * tan(ray->angle);
	step.x = TILE;
	if (!ray->right)
		step.x *= -1;
	step.y = TILE * tan(ray->angle);
	if (!ray->down && step.y > 0)
		step.y *= -1;
	if (ray->down && step.y < 0)
		step.y *= -1;
	while (intercept.x >= 0 && intercept.x <= game->lvl.width
		&& intercept.y >= 0 && intercept.y <= game->lvl.height)
	{
		if (wallhit(game, (t_fcoords){intercept.x - !ray->right, intercept.y}, &ray->doorv))
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
	float		hdis;
	float		vdis;

	vintercept = vert(game, ray);
	hintercept = horiz(game, ray);
	hdis = __FLT_MAX__;
	if (hintercept.x != -1)
		hdis = distance(game->bob.coords, hintercept);
	vdis = __FLT_MAX__;
	if (vintercept.x != -1)
		vdis = distance(game->bob.coords, vintercept);
	if (hdis < vdis)
	{
		ray->door = ray->doorh;
		ray->dis = hdis;
		ray->endpoint = hintercept;
		ray->horiz = 1;
	}
	else
	{
		ray->door = ray->doorv;
		ray->dis = vdis;
		ray->endpoint = vintercept;
		ray->horiz = 0;
	}
}
