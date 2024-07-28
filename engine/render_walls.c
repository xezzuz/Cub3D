/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:03:55 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/28 17:20:20 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	get_pixel_color(t_frame *wall, int x, int y)
{
	char	*dst;

	dst = wall->addr + (y * wall->line_length) + x * (wall->bpp / 8);
	return (*(unsigned int *)dst);
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
	// printf("%d\n",((start.y + ((height / 2) - (WINDOW_HEIGHT / 2))) * game->wall.height) / 64);
	while (i < height && start.y < WINDOW_HEIGHT)
	{
		game->wall.y_txt = ((start.y + ((height / 2) - (WINDOW_HEIGHT / 2))) * game->wall.height) / height;
		my_mlx_pixel_put(game, start.x, start.y, get_pixel_color(&txt, game->wall.offset, game->wall.y_txt));
		start.y++;
		i++;
	}
}

void	assign_tex(t_game *game, t_coords start, t_ray ray)
{
	if (ray.horizontal && ray.up)
		render_tex(game, start, ray.wall_height, game->wall.tex);
	else if (ray.horizontal && ray.down)
		render_tex(game, start, ray.wall_height, game->wall.tex1);
	if (!ray.horizontal && ray.left)
		render_tex(game, start, ray.wall_height, game->wall.tex2);
	else if (!ray.horizontal && ray.right)
		render_tex(game, start, ray.wall_height, game->wall.tex3);
}

void	render_walls(t_game *game)
{
	t_coords	start;
	int			flcl_height;
	int			i;

	start.x = 0;
	i = 0;
	while (i < NUM_OF_RAYS / WALL_COL_WIDTH)
	{
		flcl_height = (WINDOW_HEIGHT - game->rays[i].wall_height) / 2;
		start.y = ((WINDOW_HEIGHT) / 2) - (game->rays[i].wall_height / 2);
		draw_rect(game, (t_coords){start.x, 0}, 1, flcl_height, 0x181818); //0x646661
		if (game->rays[i].horizontal)
			game->wall.offset = fmod(game->rays[i].endpoint.x * (game->wall.width / TILE_SIZE), game->wall.height); // multiplying the ray hit by how much bigger the wall tex is than the actual wall and fmoding it so it loops back around the tex if it exceeds the borders. 
		else
			game->wall.offset = fmod(game->rays[i].endpoint.y * (game->wall.width / TILE_SIZE), game->wall.height);
		assign_tex(game, start, game->rays[i]);
		start.y += game->rays[i].wall_height;
		draw_rect(game, (t_coords){start.x, start.y}, 1, flcl_height, 0x181818); //0xBFC4B5
		start.x += WALL_COL_WIDTH;
		i++;
	}
}
