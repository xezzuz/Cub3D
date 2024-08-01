/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:40:02 by mmaila            #+#    #+#             */
/*   Updated: 2024/08/01 16:00:47 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	hit(t_game *game, t_fcoords check)
{
	int	x;
	int	y;

	x = floor(check.x);
	y = floor(check.y);
	if (game->lvl.map[y / TILE][x / TILE] == '1'
		|| game->lvl.map[y / TILE][x / TILE] == ' ')
		return (1);
	return (0);
}

t_fcoords	horiz(t_game *game, t_ray *ray)
{
	t_fcoords	inter;
	t_fcoords	step;

	inter.y = floor(game->bob.coords.y / TILE) * TILE;
	inter.y += (ray->down * TILE);
	inter.x = game->bob.coords.x
		+ (inter.y - game->bob.coords.y) / tan(ray->angle);
	step.y = TILE;
	if (!ray->down)
		step.y *= -1;
	step.x = TILE / tan(ray->angle);
	if (!ray->right && step.x > 0)
		step.x *= -1;
	if (ray->right && step.x < 0)
		step.x *= -1;
	while (inter.x >= 0 && inter.x <= game->lvl.width
		&& inter.y >= 0 && inter.y <= game->lvl.height)
	{
		if (hit(game, (t_fcoords){inter.x, inter.y - !ray->down}))
			return (inter);
		inter.x += step.x;
		inter.y += step.y;
	}
	inter.x = -1;
	return (inter);
}

t_fcoords	vert(t_game *game, t_ray *ray)
{
	t_fcoords	inter;
	t_fcoords	step;

	inter.x = floor(game->bob.coords.x / TILE) * TILE;
	inter.x += (ray->right * TILE);
	inter.y = game->bob.coords.y
		+ (inter.x - game->bob.coords.x) * tan(ray->angle);
	step.x = TILE;
	if (!ray->right)
		step.x *= -1;
	step.y = TILE * tan(ray->angle);
	if (!ray->down && step.y > 0)
		step.y *= -1;
	if (ray->down && step.y < 0)
		step.y *= -1;
	while (inter.x >= 0 && inter.x <= game->lvl.width
		&& inter.y >= 0 && inter.y <= game->lvl.height)
	{
		if (hit(game, (t_fcoords){inter.x - !ray->right, inter.y}))
			return (inter);
		inter.x += step.x;
		inter.y += step.y;
	}
	inter.x = -1;
	return (inter);
}

void	calc_hit(t_game *game, t_ray *ray)
{
	t_fcoords	hinter;
	t_fcoords	vinter;
	float		hdis;
	float		vdis;

	vinter = vert(game, ray);
	hinter = horiz(game, ray);
	hdis = __FLT_MAX__;
	if (hinter.x != -1)
		hdis = distance(game->bob.coords, hinter);
	vdis = __FLT_MAX__;
	if (vinter.x != -1)
		vdis = distance(game->bob.coords, vinter);
	if (hdis < vdis)
	{
		ray->dis = hdis;
		ray->hit = hinter;
		ray->horiz = 1;
		return ;
	}
	ray->dis = vdis;
	ray->hit = vinter;
	ray->horiz = 0;
}
