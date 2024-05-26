/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/25 21:14:35 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	draw_rect(t_game *game, t_coords start, int width, int height, int color)
{
	int		cols;
	int		rows;

	if (height < 0)
		return ;
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

int	get_pixel_color(t_game *game, int x, int y)
{
	char	*dst;

	dst = game->wall.texture.addr + y * game->wall.texture.line_length + x * (game->wall.texture.bits_per_pixel / 8);
	return (*(unsigned int *)dst);
}

void	render_texture_h(t_game *game, t_coords start, int height, t_ray ray)
{
	int	i;

	i = 0;
	game->wall.x_offset = floor(fmod(ray.endpoint.x * (game->wall.width / TILE_SIZE), game->wall.width));
	while (i < height)
	{
		game->wall.y_offset = (start.y + (height / 2) - (WINDOW_HEIGHT / 2)) * game->wall.height / height;
		if (start.y < 0)
		{
			i += -start.y;
			start.y = 0;
			continue ;
		}
		else if (start.y >= WINDOW_HEIGHT)
			break ;
		my_mlx_pixel_put(game, start.x, start.y, get_pixel_color(game, game->wall.x_offset, game->wall.y_offset));
		start.y++;
		i++;
	}
}

void	render_texture_v(t_game *game, t_coords start, int height, t_ray ray)
{
	int	i;

	i = 0;
	game->wall.x_offset = floor(fmod(ray.endpoint.y * (game->wall.width / TILE_SIZE), game->wall.height));
	while (i < height)
	{
		game->wall.y_offset = (start.y + (height / 2) - (WINDOW_HEIGHT / 2)) * game->wall.height / height;
		if (start.y < 0)
		{
			i += -start.y;
			start.y = 0;
			continue ;
		}
		else if (start.y >= WINDOW_HEIGHT)
			break ;
		my_mlx_pixel_put(game, start.x, start.y, get_pixel_color(game, game->wall.x_offset, game->wall.y_offset));
		start.y++;
		i++;
	}
}

void	render_walls(t_game *game)
{
	t_coords	start;
	double		p_wall_height;
	double		dppp;
	int			i;

	dppp = ((WINDOW_WIDTH) / 2) / tan(FOV / 2);
	start.x = 0;
	i = 0;
	while (i < NUM_OF_RAYS / WALL_COL_WIDTH)
	{
		p_wall_height = (TILE_SIZE * dppp) / game->rays[i].distance;
		start.y = ((WINDOW_HEIGHT) / 2) - ((int)p_wall_height / 2);
		draw_rect(game, (t_coords){start.x, 0}, 1, (WINDOW_HEIGHT - p_wall_height) / 2, 0x646661);
		if (game->rays[i].horizontal)
			render_texture_h(game, start, p_wall_height, game->rays[i]);
		else
			render_texture_v(game, start, p_wall_height, game->rays[i]);
		// draw_rect(game, start, WALL_COL_WIDTH, p_wall_height, 0xA0A597);
		draw_rect(game, (t_coords){start.x, start.y + p_wall_height}, 1, (WINDOW_HEIGHT - p_wall_height) / 2, 0xBFC4B5);
		start.x += WALL_COL_WIDTH;
		i++;
	}
}
