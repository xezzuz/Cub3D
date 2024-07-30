/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:41:58 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 15:21:24 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

size_t	array_size(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

void	free_2d(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		printf("Pointer being freed [%s]\n", array[i]);
		free(array[i++]);
	}
	free(array);
}

void	exit_cub3d(t_game *game, int flag)
{
	(void)game;
	(void)flag;
	free_2d(game->map.map);
	free_2d(game->parse.file);
	free(game->textures.north);
	free(game->textures.south);
	free(game->textures.west);
	free(game->textures.east);
	if (flag == ERROR)
		(printf("Error\n"), exit(EXIT_FAILURE)); // STDERR
	exit(EXIT_SUCCESS);
}
