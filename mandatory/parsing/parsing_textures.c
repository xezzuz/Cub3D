/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:01:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/05 12:02:13 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

char	**trim_split(char *str, char key)
{
	int		i;
	char	*trimmed;
	char	**array;

	str[ft_strlen(str) - 1] = '\0';
	while (*str == ' ')
		str++;
	if (*str != key)
		return (NULL);
	str++;
	trimmed = ft_strtrim(str, " ");
	if (!trimmed)
		return (NULL);
	if (trimmed[0] < 48 || trimmed[0] > 57
		|| trimmed[ft_strlen(trimmed) - 1] < 48
		|| trimmed[ft_strlen(trimmed) - 1] > 57)
		return (free(trimmed), NULL);
	i = -1;
	while (trimmed[++i])
		if (trimmed[i] == ',' && trimmed[i + 1] == ',')
			return (0);
	array = ft_split(trimmed, ',');
	if (!array || array_size(array) != 3)
		return (free(trimmed), free_2d(array), NULL);
	return (free(trimmed), array);
}

int	parse_colors(t_game *game, char *str, char key)
{
	int		i;
	char	**array;

	i = -1;
	array = trim_split(str, key);
	if (!array)
		return (0);
	if (key == 'C')
		while (++i < 3)
			game->textures.ceiling[i] = ft_atoi(array[i]);
	else if (key == 'F')
		while (++i < 3)
			game->textures.floor[i] = ft_atoi(array[i]);
	free_2d(array);
	return (1);
}

int	get_key_value(t_game *game, char **array, int i)
{
	if (!ft_strcmp("NO", array[0])
		&& !game->textures.north && array_size(array) == 2)
		game->textures.north = ft_strdup(array[1]);
	else if (!ft_strcmp("SO", array[0])
		&& !game->textures.south && array_size(array) == 2)
		game->textures.south = ft_strdup(array[1]);
	else if (!ft_strcmp("WE", array[0])
		&& !game->textures.west && array_size(array) == 2)
		game->textures.west = ft_strdup(array[1]);
	else if (!ft_strcmp("EA", array[0])
		&& !game->textures.east && array_size(array) == 2)
		game->textures.east = ft_strdup(array[1]);
	else if (!ft_strcmp("F", array[0])
		&& game->textures.floor[0] == ERROR)
		return (parse_colors(game, game->parse.tex_colors[i], 'F'));
	else if (!ft_strcmp("C", array[0])
		&& game->textures.ceiling[0] == ERROR)
		return (parse_colors(game, game->parse.tex_colors[i], 'C'));
	else
		return (0);
	return (1);
}

int	fill_tex_colors(t_game *game)
{
	int			i;
	int			tex;

	i = 0;
	tex = 6;
	while (game->parse.file[i] && tex)
	{
		if (!str_is_empty(game->parse.file[i]))
		{
			if (!add_to_array(&game->parse.tex_colors, game->parse.file[i]))
				return (0);
			tex--;
		}
		i++;
	}
	if (!tex)
		return (1);
	return (0);
}

int	fill_textures(t_game *game)
{
	int			i;
	char		**array;

	i = 0;
	if (!fill_tex_colors(game))
		return (0);
	while (game->parse.tex_colors[i])
	{
		array = ft_split(game->parse.tex_colors[i], ' ');
		if (!array)
			return (0);
		if (!get_key_value(game, array, i))
			return (free_2d(array), 0);
		free_2d(array);
		i++;
	}
	return (get_rgb_colors(game));
}
