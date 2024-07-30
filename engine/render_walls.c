/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 15:31:38 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	offset(t_game *game, float direction)
{
	return (fmod(direction * (game->wall.width / TILE), game->wall.height));
}

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
					* game->wall.height) / height);
		my_mlx_pixel_put(game, start.x, start.y,
			get_pixel_color(&txt, game->wall.offset, game->wall.y_txt));
		start.y++;
		i++;
	}
}

void	assign_tex(t_game *game, t_coords start, t_ray ray)
{
	if (ray.horiz && !ray.down)
		render_tex(game, start, ray.wall_height, game->wall.tex);
	else if (ray.horiz && ray.down)
		render_tex(game, start, ray.wall_height, game->wall.tex1);
	if (!ray.horiz && !ray.right)
		render_tex(game, start, ray.wall_height, game->wall.tex2);
	else if (!ray.horiz && ray.right)
		render_tex(game, start, ray.wall_height, game->wall.tex3);
}

void	render_walls(t_game *game)
{
	t_coords	start;
	int			flcl_height;
	int			i;

	start.x = 0;
	i = 0;
	while (i < NUM_OF_RAYS)
	{
		flcl_height = (WIN_HEIGHT - game->rays[i].wall_height) / 2;
		start.y = ((WIN_HEIGHT) / 2) - (game->rays[i].wall_height / 2);
		draw_rect(game, (t_coords){start.x, 0}, 1, flcl_height, WHITE);
		if (game->rays[i].horiz)
			game->wall.offset = offset(game, game->rays[i].endpoint.x); // horizontal offset of texture : multiplying the ray hit by how much bigger the wall tex is than the actual wall and fmoding it so it loops back around the tex if it exceeds the borders. 
		else
			game->wall.offset = offset(game, game->rays[i].endpoint.y);// vertical offset of texture : multiplying the ray hit by how much bigger the wall tex is than the actual wall and fmoding it so it loops back around the tex if it exceeds the borders. 
		assign_tex(game, start, game->rays[i]);
		start.y += game->rays[i].wall_height;
		draw_rect(game, (t_coords){start.x, start.y}, 1, flcl_height, WHITE);
		start.x++;
		i++;
	}
}
