/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/08 11:05:36 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

float	distance(t_coords a, t_fcoords b)
{
	return (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

void	draw_rect(t_game *game, t_coords start, t_coords end, int color)
{
	int		cols;
	int		rows;

	if (end.y < 0)
		return ;
	rows = start.y;
	while (rows < start.y + end.y)
	{
		cols = start.x;
		while (cols < start.x + end.x)
		{
			my_mlx_pixel_put(game, cols, rows, color);
			cols++;
		}
		rows++;
	}
}

void	render_tex(t_game *game, t_coords start, t_ray *ray, t_tex wall)
{
	int	i;
	int	height;
	int	yy;

	i = 0;
	yy = start.y;
	if (start.y < 0)
	{
		i += -start.y;
		start.y = 0;
	}
	if (ray->horiz)
		wall.offset = fmod(ray->hit.x
				* (wall.tex.width / TILE), wall.tex.width);
	else
		wall.offset = fmod(ray->hit.y
				* (wall.tex.width / TILE), wall.tex.height);
	height = (int)ray->wall_height;
	while (i < height && start.y < WIN_HEIGHT)
	{
		wall.y_txt = ((start.y - yy) * wall.tex.height) / height;
		my_mlx_pixel_put(game, start.x, start.y,
			get_pixel_color(&wall.tex, wall.offset, wall.y_txt));
		start.y++;
		i++;
	}
}

void	assign_tex(t_game *game, t_coords start, t_ray *ray)
{
	if (ray->door)
		render_tex(game, start, ray, game->wall[4]);
	else if (ray->horiz)
	{
		if (!ray->down)
			render_tex(game, start, ray, game->wall[0]);
		else
			render_tex(game, start, ray, game->wall[1]);
	}
	else if (!ray->horiz)
	{
		if (!ray->right)
			render_tex(game, start, ray, game->wall[2]);
		else
			render_tex(game, start, ray, game->wall[3]);
	}
}

void	render_walls(t_game *game)
{
	t_coords	start;
	t_coords	end;
	int			fch;
	int			i;

	start.x = 0;
	end.x = 1;
	i = 0;
	while (i < NUM_OF_RAYS)
	{
		fch = (WIN_HEIGHT - game->rays[i].wall_height) / 2;
		start.y = ((WIN_HEIGHT) / 2) - (game->rays[i].wall_height / 2);
		end.y = fch;
		draw_rect(game, (t_coords){start.x, 0}, end, game->textures.ceil);
		assign_tex(game, start, &game->rays[i]);
		start.y += game->rays[i].wall_height;
		draw_rect(game, start, end, game->textures.fl);
		start.x++;
		i++;
	}
}
