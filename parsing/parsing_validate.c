/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:20:14 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 15:51:14 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	validate_objects(t_game *game)
{
	int		i;
	int		j;
	int		player_count;
	char	c;

	i = 1;
	player_count = 0;
	while (i < game->lvl.rows - 1)
	{
		j = 0;
		while (game->lvl.map[i][j])
		{
			c = game->lvl.map[i][j];
			if (c == NORTH || c == SOUTH || c == WEST || c == EAST)
				(init_bob(game, i, j, c), player_count++);
			else if (c != WALL && c != FLOOR && c != EMPTY && c != DOOR)
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
	int		last;

	if (!validate_surr_ends(map, rows))
		return (0);
	i = -1;
	while (++i < rows - 2)
	{
		j = 0;
		while (map[i][j] == EMPTY)
			j++;
		if (map[i][j] != WALL)
			return (0);
		last = ft_strlen(map[i]) - 1;
		while (last && map[i][last] == EMPTY)
			last--;
		if (map[i][last] != WALL)
			return (0);
	}
	return (1);
}

int	validate_spaces(char **map)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == EMPTY)
				if (!valid_left_right(map, i, j) || !valid_up_down(map, i, j))
					return (0);
		}
	}
	return (1);
}

int	validate_shape(char **map, size_t rows)
{
	size_t		i;
	size_t		j;

	i = 1;
	while (map[i])
	{
		if (i != rows - 1 && ft_strlen(map[i]) > ft_strlen(map[i + 1]))
		{
			j = -1;
			while (map[i][++j])
				if (j >= ft_strlen(map[i + 1])
					&& map[i][j] != WALL && map[i][j] != EMPTY)
					return (0);
		}
		if (i != 0 && ft_strlen(map[i]) > ft_strlen(map[i - 1]))
		{
			j = -1;
			while (map[i][++j])
				if (j >= ft_strlen(map[i - 1])
					&& map[i][j] != WALL && map[i][j] != EMPTY)
					return (0);
		}
		i++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	game->lvl.rows = array_size(game->lvl.map);
	if (!validate_surroundings(game->lvl.map, game->lvl.rows)
		|| validate_objects(game) != 1
		|| !validate_shape(game->lvl.map, game->lvl.rows)
		|| !validate_spaces(game->lvl.map)
		|| !validate_doors(game, game->lvl.map))
		return (set_error(game, MAP), 0);
	return (1);
}
