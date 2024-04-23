/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:20:14 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/22 20:24:18 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_objects(char **map, int rows)
{
	int		i;
	int		j;
	int		player_count;
	char	c;

	i = 1;
	player_count = 0;
	while (i < rows - 1)
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c == NORTH || c == SOUTH || c == WEST || c == EAST)
					player_count++;
			else if (c != WALL && c != FLOOR && c != EMPTY)
				return (0);
			j++;
		}
		i++;
	}
	return (player_count);
}

int	validate_surroundings(char **map, int rows)
{
	int		i;
	int		j;

	i = -1;
	while (map[0][++i] == EMPTY)
		;
	while (map[0][++i])
		if (map[0][i] != WALL && map[0][i] != EMPTY)
			return (0);
	i = -1;
	while (map[0][++i] == EMPTY)
		;
	while (map[rows - 1][++i])
		if (map[rows - 1][i] != WALL && map[rows - 1][i] != EMPTY)
			return (0);
	i = -1;
	j = 0;
	while (i < rows - 1)
	{
		while (map[i][j] == EMPTY)
			j++;
		if (map[i][j] != WALL || map[i][ft_strlen(map[i]) - 1] != WALL)
			return (0);
	}
	return (1);
}

int	validate_shape(t_game *game, char **map, int rows)
{
	int		i;
	int		j;

	i = 1;
	while (map[i])
	{
		if (i != rows - 1 && ft_strlen(map[i]) > ft_strlen(map[i + 1]))
		{
			j = 0;
			while (map[i][j])
				if (j >= ft_strlen(map[i + 1]) && map[i][j] != WALL)
					return (0);
		}
		if (i != 0 && ft_strlen(map[i]) > ft_strlen(map[i - 1]))
		{
			j = 0;
			while (map[i][j])
				if (j >= ft_strlen(map[i - 1]) && map[i][j] != WALL)
					return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	game->data.rows = array_size(game->data.map);
	if (!validate_surroundings(game->data.map, game->data.rows))
		return (0);
	if (validate_objects(game->data.map, game->data.rows) != 1)
		return (0);
	if (!validate_shape(game, game->data.map, game->data.rows))
		return (0);
	return (1);
}
