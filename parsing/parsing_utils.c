/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:18:32 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 15:15:38 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	struct_init(t_game *game)
{
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.map = NULL;
	game->textures.north = NULL;
	game->textures.south = NULL;
	game->textures.east = NULL;
	game->textures.west = NULL;
	game->textures.floor[0] = ERROR;
	game->textures.ceiling[0] = ERROR;
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
		if (!add_to_array(&game->parse.file, line))
			return (close(fd), 0);
	}
	return (close(fd), 1);
}

int	get_rgb_colors(t_game *game)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		if (game->textures.floor[i] < 0 || game->textures.floor[i] > 255)
			return (0);
		if (game->textures.ceiling[i] < 0 || game->textures.ceiling[i] > 255)
			return (0);
	}
	return (1);
}

int	get_key_value(t_game *game, char **array, int i)
{
	if (!ft_strcmp("NO", array[0]) && !game->textures.north && array_size(array) == 2)
		game->textures.north = ft_strdup(array[1]);
	else if (!ft_strcmp("SO", array[0]) && !game->textures.south && array_size(array) == 2)
		game->textures.south = ft_strdup(array[1]);
	else if (!ft_strcmp("WE", array[0]) && !game->textures.west && array_size(array) == 2)
		game->textures.west = ft_strdup(array[1]);
	else if (!ft_strcmp("EA", array[0]) && !game->textures.east && array_size(array) == 2)
		game->textures.east = ft_strdup(array[1]);
	else if (!ft_strcmp("F", array[0]) && game->textures.floor[0] == ERROR)
		return (parse_colors(game, game->parse.tex_colors[i], 'F'));
	else if (!ft_strcmp("C", array[0]) && game->textures.ceiling[0] == ERROR)
		return (parse_colors(game, game->parse.tex_colors[i], 'C'));
	else
		return (0);
	return (1);
}
