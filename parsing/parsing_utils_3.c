/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:54 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/29 20:04:19 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	count_rows_cols(t_game *game)
{
	int		i;

	game->map.columns = ft_strlen(game->map.map[0]);
	i = 0;
	while (game->map.map[i])
	{
		if (ft_strlen(game->map.map[i]) > (size_t)game->map.columns)
			game->map.columns = ft_strlen(game->map.map[i]);
		i++;
	}
	game->map.rows = i;
	game->map.height = TILE * game->map.rows;
	game->map.width = TILE * game->map.columns;
}

void	init_vars(t_game *game)
{
	// check if the texture files even exist
	if (game->textures.north[ft_strlen(game->textures.north) - 1] == '\n')
		game->textures.north[ft_strlen(game->textures.north) - 1] = '\0';
	if (game->textures.south[ft_strlen(game->textures.south) - 1] == '\n')
		game->textures.south[ft_strlen(game->textures.south) - 1] = '\0';
	if (game->textures.west[ft_strlen(game->textures.west) - 1] == '\n')
		game->textures.west[ft_strlen(game->textures.west) - 1] = '\0';
	if (game->textures.east[ft_strlen(game->textures.east) - 1] == '\n')
		game->textures.east[ft_strlen(game->textures.east) - 1] = '\0';
}

void	init_bob(t_game *game, int i, int j, char direction)
{
	game->bob.coords.x = (j * TILE) + TILE / 2;
	game->bob.coords.y = (i * TILE) + TILE / 2;
	if (direction == 'N')
		game->bob.startingAngle = (M_PI * 3.0) / 2.0;
	else if (direction == 'S')
		game->bob.startingAngle = M_PI / 2.0;
	else if (direction == 'E')
		game->bob.startingAngle = 0;
	else if (direction == 'W')
		game->bob.startingAngle = M_PI;
}

int	map_is_done(char **map, int i)
{
	while (map && map[i] && str_is_empty(map[i]))
		i++;
	if (!map[i])
		return (1);
	return (0);
}
