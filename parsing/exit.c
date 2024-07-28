/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:41:58 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/28 17:19:11 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		free(array[i++]);
	free(array);
}

void	exit_cub3d(t_game *game, int flag)
{
	(void)game;
	// CLEANING
	free_2d(game->map_cub);
	free_2d(game->data.map);
	free_2d(game->texs.ch_floor);
	free_2d(game->texs.ch_ceiling);
	if (game->texs.north)
		free(game->texs.north);
	if (game->texs.south)
		free(game->texs.south);
	if (game->texs.west)
		free(game->texs.west);
	if (game->texs.east)
		free(game->texs.east);
		//
		//
		//
	if (flag == ERROR)
		(printf("Error\n"), exit(EXIT_FAILURE)); // STDERR
	exit(EXIT_SUCCESS);
}
