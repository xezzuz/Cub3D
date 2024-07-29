/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:21:51 by mmaila            #+#    #+#             */
/*   Updated: 2024/07/29 11:24:21 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_pixel_color(t_frame *wall, int x, int y)
{
	char	*dst;

	dst = wall->addr + (y * wall->line_length) + x * (wall->bpp / 8);
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data.frame.addr +
		(y * game->data.frame.line_length + x * (game->data.frame.bpp / 8));
	*(unsigned int*)dst = color;
}
