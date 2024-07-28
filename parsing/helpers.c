/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:07:48 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/28 17:19:11 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_config(t_game *game, char *mapname)
{
	int		i;

	printf("MAP NAME: %s\n", mapname);
	printf("NORTH tex: %s\n", game->texs.north);
	printf("SOUTH tex: %s\n", game->texs.south);
	printf("WEST tex: %s\n", game->texs.west);
	printf("EAST tex: %s\n", game->texs.east);
	printf("\n");
	
	i = 0;
	printf("FLOOR COLOR: ");
	if (!game->texs.ch_floor)
		printf("NONE\n");
	while (game->texs.ch_floor && game->texs.ch_floor[i])
		printf("[%s]", game->texs.ch_floor[i++]);
	printf("\n");
	i = 0;
	printf("CEILING COLOR: ");
	if (!game->texs.ch_ceiling)
		printf("NONE\n");
	while (game->texs.ch_ceiling && game->texs.ch_ceiling[i])
		printf("[%s]", game->texs.ch_ceiling[i++]);
	printf("\n\n");
	
	i = 0;
	printf("GAME MAP:\n");
	if (!game->data.map)
		printf("NONE\n");
	while (game->data.map && game->data.map[i])
		printf("%s\n", game->data.map[i++]);
}
