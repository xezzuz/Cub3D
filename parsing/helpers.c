/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:07:48 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/29 10:26:02 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_config(t_game *game, char *mapname)
{
	int		i;

	i = 0;
	printf("PARSED FILE\n-----------------------------------------------------------\n");
	while (game->parse.file[i])
		printf("%s\n", game->parse.file[i++]);
	printf("\n-----------------------------------------------------------\n\n\n\n");

	i = 0;
	printf("TEXTURES AND COLORS\n-----------------------------------------------------------\n");
	while (game->parse.tex_colors[i])
		printf("%s", game->parse.tex_colors[i++]);
	printf("\n-----------------------------------------------------------\n\n\n\n");

	printf("MAP NAME: %s\n", mapname);
	printf("NORTH TEXTURE: %s\n", game->textures.north);
	printf("SOUTH TEXTURE: %s\n", game->textures.south);
	printf("WEST TEXTURE: %s\n", game->textures.west);
	printf("EAST TEXTURE: %s\n", game->textures.east);
	printf("\n");
	
	i = 0;
	printf("FLOOR COLOR: ");
	if (!game->textures.ch_floor)
		printf("NONE\n");
	while (game->textures.ch_floor && game->textures.ch_floor[i])
		printf("[%s]", game->textures.ch_floor[i++]);
	printf("\n");
	i = 0;
	printf("CEILING COLOR: ");
	if (!game->textures.ch_ceiling)
		printf("NONE\n");
	while (game->textures.ch_ceiling && game->textures.ch_ceiling[i])
		printf("[%s]", game->textures.ch_ceiling[i++]);
	printf("\n\n");
	
	printf("GAME MAP:\n");
	if (!game->data.map)
		printf("NONE\n");
	i = 0;
	while (game->data.map && game->data.map[i])
		printf("%s\n", game->data.map[i++]);
}
