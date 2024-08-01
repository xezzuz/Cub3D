/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:10:31 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 10:24:22 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	fill_map_ends(t_game *game)
{
	int		i;
	int		j;
	char	**result;

	result = malloc(sizeof(char *) * (game->lvl.rows + 1));
	if (!result)
		return (set_error(game, ALLOC), 0);
	i = 0;
	while (i < game->lvl.rows)
	{
		result[i] = malloc(game->lvl.columns + 1);
		if (!result[i])
			return (free_2d(result), set_error(game, ALLOC), 0);
		ft_strlcpy(result[i], game->lvl.map[i], game->lvl.columns + 1);
		j = ft_strlen(game->lvl.map[i]);
		while (j < game->lvl.columns)
			result[i][j++] = ' ';
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	free_2d(game->lvl.map);
	game->lvl.map = result;
	return (1);
}

t_door	*alloc_doors(char **map)
{
	int		i;
	int		j;
	int		count;
	t_door	*doors;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	doors = (t_door *) malloc((count * sizeof(t_door)));
	return (doors);
}

int	validate_surr_ends(char **map, int rows)
{
	int		i;

	i = -1;
	while (map[0][++i])
		if (map[0][i] != WALL && map[0][i] != EMPTY)
			return (0);
	i = -1;
	while (map[rows - 1][++i])
		if (map[rows - 1][i] != WALL && map[rows - 1][i] != EMPTY)
			return (0);
	return (1);
}

int	valid_up_down(char **map, size_t i, size_t j)
{
	if (i > 0 && j < ft_strlen(map[i - 1]))
		if (map[i - 1][j] != EMPTY && map[i - 1][j] != WALL)
			return (0);
	if (map[i + 1] && j < ft_strlen(map[i + 1]))
		if (map[i + 1][j] != EMPTY && map[i + 1][j] != WALL)
			return (0);
	return (1);
}

int	valid_left_right(char **map, size_t i, size_t j)
{
	if (map[i][j + 1])
		if (map[i][j + 1] != EMPTY && map[i][j + 1] != WALL)
			return (0);
	if (j >= 1)
		if (map[i][j - 1] != EMPTY && map[i][j - 1] != WALL)
			return (0);
	return (1);
}
