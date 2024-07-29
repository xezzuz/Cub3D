/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:37:40 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/29 18:42:40 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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
	game->map = malloc(sizeof(char *) * (map_size + 1));
	if (!game->map)
		return (0);
	j = 0;
	while (game->parse.file[i] && !map_is_done(game->parse.file, i))
	{
		if (game->parse.file[i][ft_strlen(game->parse.file[i]) - 1] == '\n')
			game->parse.file[i][ft_strlen(game->parse.file[i]) - 1] = '\0';
		game->map[j++] = ft_strdup(game->parse.file[i++]);
	}
	game->map[j] = NULL;
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
	if (tex)
		return (1);
	return (0);
}

int	fill_textures(t_game *game)
{
	int			i;
	char		**array;

	i = 0;
	if (fill_tex_colors(game))
		return (0);
	while (game->parse.tex_colors[i])
	{
		array = ft_split(game->parse.tex_colors[i], ' ');
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
	int		file_size;

	struct_init(game);
	game->parse.tex_colors = NULL;
	if (fill_textures(game))
		return (0);
	file_size = array_size(game->parse.file) - 6;
	if (file_size <= 3)
		return (0);
	return (fill_map(game, file_size));
}

int	parsing(t_game *game, char *map_name)
{
	if (!map_extension(map_name))
		return (0);
	game->parse.file = NULL;
	if (!read_config(game, map_name))
		return (0);
	if (!fill_struct(game))
		return (0);
	if (!validate_map(game))
		return (0);
	init_vars(game);
	printf("[%s]\n", game->textures.north);
	// printf("\n\n\n\n");
	// ft_print_config(game, map_name);
	return (1);
}
