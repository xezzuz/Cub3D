/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:37:40 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/08 13:59:19 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	struct_init(t_game *game)
{
	int			i;

	i = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->lvl.rows = 0;
	game->lvl.columns = 0;
	game->parse.err = NULL;
	game->lvl.map = NULL;
	game->lvl.doors = NULL;
	game->parse.file = NULL;
	game->parse.tex_colors = NULL;
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.east = NULL;
	game->textures.west = NULL;
	game->textures.floor[0] = ERROR;
	game->textures.ceiling[0] = ERROR;
	game->frame.img = NULL;
	while (i < 4)
		game->wall[i++].tex.img = NULL;
	i = -1;
	while (++i < NUM_FRAMES)
		game->animation[i] = NULL;
}

int	parsing(t_game *game, char *map_name)
{
	struct_init(game);
	if (!map_extension(map_name) || !read_config(game, map_name))
		return (0);
	if (!fill_struct(game) || !validate_map(game) || !config_exist(game))
		return (0);
	if (!map_is_rect(game))
		return (fill_map_ends(game));
	return (1);
}
