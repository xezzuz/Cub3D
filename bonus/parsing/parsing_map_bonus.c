/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:05:57 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 16:10:57 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

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

int	fill_map(t_game *game, int map_size)
{
	int			i;
	int			j;
	int			non_empty;

	i = -1;
	non_empty = 0;
	while (game->parse.file[++i] && non_empty < 6)
		if (!str_is_empty(game->parse.file[i]))
			non_empty++;
	while (str_is_empty(game->parse.file[i]))
		i++;
	game->lvl.map = malloc(sizeof(char *) * (map_size + 1));
	if (!game->lvl.map)
		return (0);
	j = 0;
	while (game->parse.file[i] && !map_is_done(game->parse.file, i))
	{
		if (game->parse.file[i][ft_strlen(game->parse.file[i]) - 1] == '\n')
			game->parse.file[i][ft_strlen(game->parse.file[i]) - 1] = '\0';
		game->lvl.map[j++] = ft_strdup(game->parse.file[i++]);
	}
	game->lvl.map[j] = NULL;
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
