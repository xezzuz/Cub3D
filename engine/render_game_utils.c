/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:04:22 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 13:43:03 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	render_minimap(t_game *game)
{
	t_coords		diff;
	t_coords		center;
	int				x;
	int				y;
	
	center.x = 156;
	center.y = 156;
	diff.x = center.x - game->bob.coords.x;
	diff.y = center.y - game->bob.coords.y;
	draw_rect(game, (t_coords){7, 312}, 300, 7, 0x62645F);
	draw_rect(game, (t_coords){7, 19}, 5, 300, 0x62645F);
	draw_rect(game, (t_coords){12, 12}, 300, 300, 0x2F312D);
	x = 0;
	while (x < game->lvl.width)
	{
		y = 0;
		while (y < game->lvl.height)
		{
			if (x + diff.x <= 312 && x + diff.x >= 12
				&& y + diff.y <= 312 && y + diff.y >= 12)
				if (game->lvl.map[y / TILE][x / TILE] == '0'
					|| game->lvl.map[y / TILE][x / TILE] == 'S'
					|| game->lvl.map[y / TILE][x / TILE] == 'N'
					|| game->lvl.map[y / TILE][x / TILE] == 'E'
					|| game->lvl.map[y / TILE][x / TILE] == 'W'
					|| game->lvl.map[y / TILE][x / TILE] == 'D')
					my_mlx_pixel_put(game, x + diff.x, y + diff.y, WHITE);
			y++;
		}
		x++;
	}
	draw_rect(game, (t_coords){153, 153}, 6, 6, RED);
}
