/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:37:40 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/21 19:18:54 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_map(t_game *game, int map_size)
{
	int		i;

	i = 0;
	game->data.map = malloc (sizeof(char *) * (map_size + 1));
	if (!game->data.map)
		return (0);
	while (game->map_cub[i + 6])
	{
		game->data.map[i] = ft_strdup(game->map_cub[i + 6]); //?
		i++;
	}
	game->data.map[i] = NULL;
	return (1);
}

int	fill_textures(t_game *game)
{
	int		i;
	char	**array;

	i = 0;
	while (game->map_cub[i] && i <= 5)
	{
		array = ft_split(game->map_cub[i], ' ');
		if (array_size(array) != 2)
			return (free_2d(array), 0);
		if (!get_key_value(game, array))
			return (free_2d(array), 0);
		free_2d(array);
		i++;
	}
	return (get_rgb_colors(game));
}

int	fill_struct(t_game *game)
{
	int		map_size;

	struct_init(game);
	fill_textures(game);
	map_size = array_size(game->map_cub) - 6;
	if (map_size <= 3)
		return (0);
	fill_map(game, map_size);
	return (1);
}

int	parsing(t_game *game, char *map_name)
{
	if (!map_extension(map_name))
		return (0);
	if (!read_config(game, map_name))
		return (0);
	if (!fill_struct(game))
		return (0);
	if (!validate_config(game))
		return (0);
	if (!validate_map(game))
		return (0);
	ft_print_config(game, map_name);
	return (1);
}
