/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:59:06 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 10:01:18 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	map_extension(char *map_name)
{
	int		len;

	len = ft_strlen(map_name);
	if (len <= 4)
		return (0);
	while (*map_name)
		map_name++;
	if (ft_strncmp(".cub", map_name - 4, 4) != 0)
		return (print_stderr(FNF), 0);
	return (1);
}

int	read_config(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (set_error(game, FNF), 0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line && !game->parse.file)
			return (set_error(game, ALLOC), close(fd), 0);
		if (!line)
			break ;
		if (!add_to_array(&game->parse.file, line))
			return (close(fd), set_error(game, ALLOC), 0);
	}
	return (close(fd), 1);
}

int	fill_struct(t_game *game)
{
	int		file_size;

	if (!fill_textures(game))
		return (set_error(game, TXT), 0);
	file_size = array_size(game->parse.file) - 6;
	if (file_size < 3)
		return (set_error(game, MAP), 0);
	return (fill_map(game, file_size));
}
