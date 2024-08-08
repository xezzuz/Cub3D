/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:58:51 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/08 13:04:30 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
