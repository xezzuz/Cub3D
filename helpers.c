/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:07:48 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/20 18:32:22 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_config(t_game *game, char *mapname)
{
	int		i;

	printf("MAP NAME: %s\n", mapname);
	printf("NORTH TEXTURE: %s\n", game->textures.north);
	printf("SOUTH TEXTURE: %s\n", game->textures.south);
	printf("WEST TEXTURE: %s\n", game->textures.west);
	printf("EAST TEXTURE: %s\n", game->textures.east);
	printf("\n");
	
	i = 0;
	printf("FLOOR COLOR: ");
	if (!game->textures.floor)
		printf("NONE\n");
	while (game->textures.floor && game->textures.floor[i])
		printf("[%s]", game->textures.floor[i++]);
	printf("\n");
	i = 0;
	printf("CEILING COLOR: ");
	if (!game->textures.ceiling)
		printf("NONE\n");
	while (game->textures.ceiling && game->textures.ceiling[i])
		printf("[%s]", game->textures.ceiling[i++]);
	printf("\n\n");
	
	i = 0;
	printf("GAME MAP:\n");
	if (!game->data.map)
		printf("NONE\n");
	while (game->data.map && game->data.map[i])
		printf("%s\n", game->data.map[i++]);
}
