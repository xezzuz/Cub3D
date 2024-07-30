/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:49:54 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 17:41:56 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	open_textures(t_game *game)
{
	int		i;
	int		fds[4];

	fds[0] = open(game->textures.north, O_RDONLY);
	fds[1] = open(game->textures.south, O_RDONLY);
	fds[2] = open(game->textures.east, O_RDONLY);
	fds[3] = open(game->textures.west, O_RDONLY);
	i = -1;
	while (++i < 4)
		if (fds[i] == -1)
			return (close(fds[0]), close(fds[1]), close(fds[2]), close(fds[3]), set_error(game, TXT), 0);
	return (1);
}

void	count_rows_cols(t_game *game)
{
	int	col_len;

	game->map.columns = ft_strlen(game->map.map[0]);
	game->map.rows = 0;
	while (game->map.map[game->map.rows])
	{
		col_len = ft_strlen(game->map.map[game->map.rows]);
		if (col_len > game->map.columns)
			game->map.columns = col_len;
		game->map.rows++;
	}
	game->map.height = TILE * game->map.rows;
	game->map.width = TILE * game->map.columns;
}

int	config_exist(t_game *game)
{
	if (!game->textures.north || !game->textures.south
		|| !game->textures.west || !game->textures.east
		|| game->textures.floor[0] == ERROR || game->textures.ceiling[0] == ERROR)
		return (set_error(game, TXT), 0);
	if (game->textures.north[ft_strlen(game->textures.north) - 1] == '\n')
		game->textures.north[ft_strlen(game->textures.north) - 1] = '\0';
	if (game->textures.south[ft_strlen(game->textures.south) - 1] == '\n')
		game->textures.south[ft_strlen(game->textures.south) - 1] = '\0';
	if (game->textures.west[ft_strlen(game->textures.west) - 1] == '\n')
		game->textures.west[ft_strlen(game->textures.west) - 1] = '\0';
	if (game->textures.east[ft_strlen(game->textures.east) - 1] == '\n')
		game->textures.east[ft_strlen(game->textures.east) - 1] = '\0';
	return (open_textures(game));
}

void	init_bob(t_game *game, int i, int j, char direction)
{
	game->bob.coords.x = (j * TILE) + TILE / 2;
	game->bob.coords.y = (i * TILE) + TILE / 2;
	if (direction == 'N')
		game->bob.rot_angle = (M_PI * 3.0) / 2.0;
	else if (direction == 'S')
		game->bob.rot_angle = M_PI / 2.0;
	else if (direction == 'E')
		game->bob.rot_angle = 0;
	else if (direction == 'W')
		game->bob.rot_angle = M_PI;
}

int	map_is_done(char **map, int i)
{
	while (map && map[i] && str_is_empty(map[i]))
		i++;
	if (!map[i])
		return (1);
	return (0);
}
