/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:42:56 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/08 14:03:54 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	free_mlx(t_game *game)
{
	int			i;

	i = 0;
	while (i < 5)
	{
		if (game->wall[i].tex.img)
			mlx_destroy_image(game->mlx, game->wall[i].tex.img);
		i++;
	}
	i = 0;
	while (i < NUM_FRAMES)
	{
		if (game->animation[i])
			mlx_destroy_image(game->mlx, game->animation[i]);
		i++;
	}
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}
