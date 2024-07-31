/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 18:52:17 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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

void	render_tex(t_game *game, t_coords start, int height, t_frame txt)
{
	int	i;

	i = 0;
	if (start.y < 0)
	{
		i += -start.y;
		start.y = 0;
	}
	while (i < height && start.y < WIN_HEIGHT)
	{
		game->wall.y_txt = roundf(((start.y + (height / 2) - (WIN_HEIGHT / 2))
					* txt.height) / height);
		my_mlx_pixel_put(game, start.x, start.y,
			get_pixel_color(&txt, game->wall.offset, game->wall.y_txt));
		start.y++;
		i++;
	}
}

void	assign_tex(t_game *game, t_coords start, t_ray *ray)
{
	if (ray->door)
	{
		game->wall.offset = fmod(ray->hit.y, 64);
		if (ray->horiz)
			game->wall.offset = fmod(ray->hit.x, 64);
		render_tex(game, start, ray->wall_height, game->wall.doortex);
	}
	else if (ray->horiz)
	{
		game->wall.offset = fmod(ray->hit.x
				* (game->wall.tex.width / TILE), game->wall.tex.width);
		if (!ray->down)
			render_tex(game, start, ray->wall_height, game->wall.tex);
		else
			render_tex(game, start, ray->wall_height, game->wall.tex1);
	}
	else if (!ray->horiz)
	{
		game->wall.offset = fmod(ray->hit.y
				* (game->wall.tex2.width / TILE), game->wall.tex2.height);
		if (!ray->right)
			render_tex(game, start, ray->wall_height, game->wall.tex2);
		else
			render_tex(game, start, ray->wall_height, game->wall.tex3);
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
