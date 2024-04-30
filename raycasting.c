/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:51:31 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/30 19:30:24 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	render_fov(t_game *game)
{
	t_coords	endpoint;
	double		inc;
	double		current_angle;
	double		last_ray_angle;
	int			x;

	x = 0;
	current_angle = game->bob.rotationAngle - (FOV / 2);
	last_ray_angle = game->bob.rotationAngle + (FOV / 2);
	while (current_angle < last_ray_angle)
	{
		// printf("current_angle = %.1f\n", current_angle);
		// printf("player_angle = %.1f\n", game->bob.rotationAngle);
		// printf("last_angle = %.1f\n", last_ray_angle);
		x += WALL_COL_WIDTH;
		endpoint.x = game->bob.coords.x + cos(current_angle) * 2000;
		endpoint.y = game->bob.coords.y + sin(current_angle) * 2000;
		draw_line(game, x, game->bob.coords, endpoint, GRAY);
		inc = ((FOV) / (WIDTH / 3));
		// printf("inc = %f\n", inc);
		current_angle += inc;
	}
}
