/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:58:51 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/23 18:37:47 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_to_file(t_game *game, char *line)
{
	int		i;
	char	**result;

	if (!game->parse.file)
	{
		result = malloc (sizeof(char *) * 2);
		if (!result)
			return (0);
		result[0] = line;
		result[1] = NULL;
	}
	else
	{
		result = malloc (sizeof(char *) * (array_size(game->parse.file) + 2));
		if (!result)
			return (0);
		i = -1;
		while (game->parse.file && game->parse.file[++i])
			result[i] = game->parse.file[i];
		result[i] = line;
		result[i + 1] = NULL;
	}
	free(game->parse.file);
	game->parse.file = result;
	return (1);
}
