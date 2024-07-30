/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:41:58 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 16:05:13 by mmaila           ###   ########.fr       */
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

int	exit_cub3d(t_game *game)
{
	free_2d(game->map.map);
	free_2d(game->parse.file);
	free(game->textures.north);
	free(game->textures.south);
	free(game->textures.west);
	free(game->textures.east);
	// if (flag == ERROR)
	// 	(printf("Error\n"), exit(EXIT_FAILURE)); // STDERR
	// exit(EXIT_SUCCESS);
	exit(0);
	return (0);
}

