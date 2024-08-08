/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:48:19 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/08 14:04:57 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

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

int	open_textures(t_game *game)
{
	int		i;
	int		fds[5];

	fds[0] = open(game->textures.north, O_RDONLY);
	fds[1] = open(game->textures.south, O_RDONLY);
	fds[2] = open(game->textures.east, O_RDONLY);
	fds[3] = open(game->textures.west, O_RDONLY);
	fds[4] = open("./textures/joker", O_RDONLY);
	i = -1;
	while (++i < 5)
		if (fds[i] == -1)
			return (close(fds[0]), close(fds[1]),
				close(fds[2]), close(fds[3]),
				close(fds[4]), set_error(game, TXT), 0);
	return (close(fds[0]), close(fds[1]),
		close(fds[2]), close(fds[3]), close(fds[4]), 1);
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
