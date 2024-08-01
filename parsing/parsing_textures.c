/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:01:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 10:03:28 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	get_rgb_colors(t_game *game)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (game->textures.floor[i] < 0 || game->textures.floor[i] > 255)
			return (0);
		if (game->textures.ceiling[i] < 0 || game->textures.ceiling[i] > 255)
			return (0);
		i++;
	}
	game->textures.ceil = (game->textures.ceiling[0] << 16)
		| (game->textures.ceiling[1] << 8)
		| game->textures.ceiling[2];
	game->textures.fl = (game->textures.floor[0] << 16)
		| (game->textures.floor[1] << 8)
		| game->textures.floor[2];
	return (1);
}

int	parse_colors(t_game *game, char *str, char key)
{
	int		i;
	int		num_counter;

	num_counter = 0;
	if (!count_commas(str))
		return (0);
	i = 0;
	while (str[i++] == ' ')
		;
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
