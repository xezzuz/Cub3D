/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:42:56 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/08 14:04:27 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	free_mlx(t_game *game)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (game->wall[i].tex.img)
			mlx_destroy_image(game->mlx, game->wall[i].tex.img);
		i++;
	}
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
}
