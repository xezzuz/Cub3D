/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:48:19 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 10:14:57 by nazouz           ###   ########.fr       */
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

int	open_textures(t_game *game)
{
	int		i;
	int		fds[4];

	fds[0] = open(game->textures.north, O_RDONLY);
	fds[1] = open(game->textures.south, O_RDONLY);
	fds[2] = open(game->textures.east, O_RDONLY);
	fds[3] = open(game->textures.west, O_RDONLY);
	i = -1;
	while (++i < 4)
		if (fds[i] == -1)
			return (close(fds[0]), close(fds[1]),
				close(fds[2]), close(fds[3]), set_error(game, TXT), 0);
	return (1);
}

int	config_exist(t_game *game)
{
	if (!game->textures.north || !game->textures.south
		|| !game->textures.west || !game->textures.east
		|| game->textures.floor[0] == ERROR
		|| game->textures.ceiling[0] == ERROR)
		return (set_error(game, TXT), 0);
	if (game->textures.north[ft_strlen(game->textures.north) - 1] == '\n')
		game->textures.north[ft_strlen(game->textures.north) - 1] = '\0';
	if (game->textures.south[ft_strlen(game->textures.south) - 1] == '\n')
		game->textures.south[ft_strlen(game->textures.south) - 1] = '\0';
	if (game->textures.west[ft_strlen(game->textures.west) - 1] == '\n')
		game->textures.west[ft_strlen(game->textures.west) - 1] = '\0';
	if (game->textures.east[ft_strlen(game->textures.east) - 1] == '\n')
		game->textures.east[ft_strlen(game->textures.east) - 1] = '\0';
	return (open_textures(game));
}
