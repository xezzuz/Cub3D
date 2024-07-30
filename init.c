/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:18:54 by mmaila            #+#    #+#             */
/*   Updated: 2024/07/29 18:05:22 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

void	init_data(t_game *game)
{
	game->bob.moveSpeed = 4.0;
	game->bob.rot_speed = 1.4 * (M_PI / 180);
	game->bob.rot_angle = game->bob.startingAngle;
	game->bob.dppp = ((WIN_WIDTH) / 2) / tan(FOV / 2);
	game->mouse_angle = 0;
	game->bob.turn_dir = 0;
	game->bob.upright = 0;
	game->bob.sideways = 0;
}

void	init_images(t_game *game)
{
	// check if the textures exists
	game->frame.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bpp, &game->frame.line_length, &game->frame.endian);
	game->wall.tex.img = mlx_xpm_file_to_image(game->mlx, game->textures.north, &game->wall.width, &game->wall.height);
	game->wall.tex1.img = mlx_xpm_file_to_image(game->mlx, game->textures.south, &game->wall.width, &game->wall.height);
	game->wall.tex2.img = mlx_xpm_file_to_image(game->mlx, game->textures.west, &game->wall.width, &game->wall.height);
	game->wall.tex3.img = mlx_xpm_file_to_image(game->mlx, game->textures.east, &game->wall.width, &game->wall.height);
	game->wall.tex.addr = mlx_get_data_addr(game->wall.tex.img, &game->wall.tex.bpp, &game->wall.tex.line_length, &game->wall.tex.endian);
	game->wall.tex1.addr = mlx_get_data_addr(game->wall.tex1.img, &game->wall.tex1.bpp, &game->wall.tex1.line_length, &game->wall.tex1.endian);
	game->wall.tex2.addr = mlx_get_data_addr(game->wall.tex2.img, &game->wall.tex2.bpp, &game->wall.tex2.line_length, &game->wall.tex2.endian);
	game->wall.tex3.addr = mlx_get_data_addr(game->wall.tex3.img,&game->wall.tex3.bpp, &game->wall.tex3.line_length, &game->wall.tex3.endian);
}

void	setup_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1); //
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "R|D");
	if (!game->win)
		exit(1); //
	init_images(game);
	init_data(game);
}