/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:18:32 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/21 19:33:32 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_init(t_game *game)
{
	game->data.map = NULL;
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.east = NULL;
	game->textures.west = NULL;
	game->textures.ch_floor = NULL;
	game->textures.ch_ceiling = NULL;
}

int	map_extension(char *map_name)
{
	int		len;

	len = ft_strlen(map_name);
	if (len <= 4)
		return (0);
	while (*map_name)
		map_name++;
	if (ft_strncmp(".cub", map_name - 4, 4) != 0)
		return (0);
	return (1);
}

int	read_config(t_game *game, char *map_name)
{
	int		fd;
	char	buff[2];
	char	*map;

	game->map_cub = NULL;
	map = NULL;
	buff[1] = '\0';
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, buff, 1) > 0)
	{
		map = ft_strjoin(map, buff);
		if (!map)
			return (0);
	}
	game->map_cub = ft_split(map, '\n');
	if (!game->map_cub)
		return (0);
	// CLOSE FD
	return (1);
}

int	get_rgb_colors(t_game *game)
{
	int		i;

	if (array_size(game->textures.ch_floor) != 3
		|| array_size(game->textures.ch_ceiling) != 3)
		return (0);
	i = -1;
	while (++i < 3)
	{
		game->textures.floor[i] = ft_atoi(game->textures.ch_floor[i]);
		if (game->textures.floor[i] < 0 || game->textures.floor[i] > 255)
			return (0);
		game->textures.ceiling[i] = ft_atoi(game->textures.ch_ceiling[i]);
		if (game->textures.ceiling[i] < 0 || game->textures.ceiling[i] > 255)
			return (0);
	}
	return (1);
}

int	get_key_value(t_game *game, char **array)
{
	if (!strcmp("NO", array[0]) && !game->textures.north)
		game->textures.north = ft_strdup(array[1]);
	else if (!strcmp("SO", array[0]) && !game->textures.south)
		game->textures.south = ft_strdup(array[1]);
	else if (!strcmp("WE", array[0]) && !game->textures.west)
		game->textures.west = ft_strdup(array[1]);
	else if (!strcmp("EA", array[0]) && !game->textures.east)
		game->textures.east = ft_strdup(array[1]);
	else if (!strcmp("F", array[0]) && !game->textures.floor)
		game->textures.ch_floor = ft_split(array[1], ',');
	else if (!strcmp("C", array[0]) && !game->textures.ceiling)
		game->textures.ch_ceiling = ft_split(array[1], ',');
	else
		return (0);
	return (1);
}
