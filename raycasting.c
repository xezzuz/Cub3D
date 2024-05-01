/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:51:31 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/01 16:13:03 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	render_fov(t_game *game)
{
	int			x;
	double		current_angle;
	double		last_ray_angle;
	t_coords	endpoint;

	x = 0;
	current_angle = game->bob.rotationAngle - ((FOV) / 2);
	last_ray_angle = game->bob.rotationAngle + ((FOV) / 2);
	while (current_angle < last_ray_angle && x + WALL_COL_WIDTH < WIDTH)
	{
		endpoint.x = game->bob.coords.x + (cos(current_angle) * 2000);
		endpoint.y = game->bob.coords.y + (sin(current_angle) * 2000);
		draw_line(game, x, game->bob.coords, endpoint, GRAY);
		current_angle += ((FOV) / (WIDTH / WALL_COL_WIDTH));
		x += WALL_COL_WIDTH;
	}
}
