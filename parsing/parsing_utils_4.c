/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:48:19 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 13:52:59 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	count_commas(char *str)
{
	int			i;
	int			comma;

	if (!str)
		return (0);
	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i++] == ',')
		{
			comma++;
			while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
				i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (0);
		}
	}
	return (comma == 2);
}

int	parse_colors(t_game *game, char *str, char key)
{
	int		i;
	int		num_counter;

	num_counter = 0;
	if (!count_commas(str))
		return (0);
	i = 0;
	while (str[i++] == ' ');
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (num_counter == 3)
			return (0);
		if (key == 'C')
			game->textures.ceiling[num_counter++] = ft_atoi(&str[i]);
		else
			game->textures.floor[num_counter++] = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == ',')
			i++;
	}
	return (num_counter == 3);
}

int	map_is_rect(t_game *game)
{
	int			i;

	count_rows_cols(game);
	i = -1;
	while (game->map.map[++i])
	{
		if (ft_strlen(game->map.map[i]) != (size_t)game->map.columns)
			return (0);
	}
	return (1);
}

int	fill_map_ends(t_game *game)
{
	int		i;
	int		j;
	char	**result;

	result = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < game->map.rows)
	{
		result[i] = ft_strdup(game->map.map[i]);
		if (!result[i])
			return (free_2d(result), 0);
		j = ft_strlen(game->map.map[i]);
		while (j < game->map.columns)
			result[i][j++] = ' ';
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	// free_2d(game->map.map);
	game->map.map = result;
	return (1);
}
