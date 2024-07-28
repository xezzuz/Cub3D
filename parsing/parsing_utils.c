/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:18:32 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/28 17:19:11 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_init(t_game *game)
{
	game->data.map = NULL;
	game->texs.north = NULL;
	game->texs.south = NULL;
	game->texs.east = NULL;
	game->texs.west = NULL;
	game->texs.ch_floor = NULL;
	game->texs.ch_ceiling = NULL;
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
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!add_to_file(game, line)) //?
			return (close(fd), 0);
	}
	return (close(fd), 1);
}

int	get_rgb_colors(t_game *game)
{
	int		i;

	if (array_size(game->texs.ch_floor) != 3
		|| array_size(game->texs.ch_ceiling) != 3)
		return (0);
	i = -1;
	while (++i < 3)
	{
		game->texs.floor[i] = ft_atoi(game->texs.ch_floor[i]);
		if (game->texs.floor[i] < 0 || game->texs.floor[i] > 255)
			return (0);
		game->texs.ceiling[i] = ft_atoi(game->texs.ch_ceiling[i]);
		if (game->texs.ceiling[i] < 0 || game->texs.ceiling[i] > 255)
			return (0);
	}
	return (1);
}

int	get_key_value(t_game *game, char **array)
{
	if (!strcmp("NO", array[0]) && !game->texs.north)
		game->texs.north = ft_strdup(array[1]);
	else if (!strcmp("SO", array[0]) && !game->texs.south)
		game->texs.south = ft_strdup(array[1]);
	else if (!strcmp("WE", array[0]) && !game->texs.west)
		game->texs.west = ft_strdup(array[1]);
	else if (!strcmp("EA", array[0]) && !game->texs.east)
		game->texs.east = ft_strdup(array[1]);
	else if (!strcmp("F", array[0]) && !game->texs.ch_floor)
		game->texs.ch_floor = ft_split(array[1], ',');
	else if (!strcmp("C", array[0]) && !game->texs.ch_ceiling)
		game->texs.ch_ceiling = ft_split(array[1], ',');
	else
		return (0);
	return (1);
}
