/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:58:51 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/29 15:32:12 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int validate_surr_ends(char **map, int rows)
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

int	str_is_empty(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		else
			return (0);
	}
	return (1);
}

int	add_to_array(char ***array, char *line)
{
	int		i;
	char	**result;

	if (!*array)
	{
		result = malloc(sizeof(char *) * 2);
		if (!result)
			return (0);
		result[0] = line;
		result[1] = NULL;
	}
	else
	{
		result = malloc(sizeof(char *) * (array_size(*array) + 2));
		if (!result)
			return (0);
		i = -1;
		while (*array && (*array)[++i])
			result[i] = (*array)[i];
		result[i] = line;
		result[i + 1] = NULL;
	}
	free(*array);
	*array = result;
	return (1);
}
