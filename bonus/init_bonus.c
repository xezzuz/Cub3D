/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:18:54 by mmaila            #+#    #+#             */
/*   Updated: 2024/08/04 17:18:03 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d_bonus.h"

void	init_data(t_game *game)
{
	game->bob.move_speed = 4.0;
	game->bob.rot_speed = 1.4 * (M_PI / 180);
	game->bob.dppp = ((WIN_WIDTH) / 2) / tan(FOV / 2);
	game->mouse_angle = 0;
	game->bob.turn_dir = 0;
	game->bob.upright = 0;
	game->bob.sideways = 0;
	game->mouse_hidden = 1;
}

void	init_textures(t_game *game)
{
	game->wall[0].tex.img
		= mlx_xpm_file_to_image(game->mlx, game->textures.north,
			&game->wall[0].tex.width, &game->wall[0].tex.height);
	game->wall[1].tex.img
		= mlx_xpm_file_to_image(game->mlx, game->textures.south,
			&game->wall[1].tex.width, &game->wall[1].tex.height);
	game->wall[2].tex.img
		= mlx_xpm_file_to_image(game->mlx, game->textures.west,
			&game->wall[2].tex.width, &game->wall[2].tex.height);
	game->wall[3].tex.img
		= mlx_xpm_file_to_image(game->mlx, game->textures.east,
			&game->wall[3].tex.width, &game->wall[3].tex.height);
	game->wall[4].tex.img
		= mlx_xpm_file_to_image(game->mlx, "./textures/joker",
			&game->wall[4].tex.width, &game->wall[4].tex.height);
	if (!game->wall[0].tex.img || !game->wall[1].tex.img
		|| !game->wall[2].tex.img || !game->wall[3].tex.img
		|| !game->wall[4].tex.img)
		(set_error(game, TXT), exit_cub3d(game));
}

void	init_images(t_game *game)
{
	game->frame.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->frame.addr
		= mlx_get_data_addr(game->frame.img, &game->frame.bpp,
			&game->frame.line_length, &game->frame.endian);
	init_textures(game);
	game->wall[4].tex.addr
		= mlx_get_data_addr(game->wall[4].tex.img, &game->wall[4].tex.bpp,
			&game->wall[4].tex.line_length, &game->wall[4].tex.endian);
	game->wall[0].tex.addr
		= mlx_get_data_addr(game->wall[0].tex.img, &game->wall[0].tex.bpp,
			&game->wall[0].tex.line_length, &game->wall[0].tex.endian);
	game->wall[1].tex.addr
		= mlx_get_data_addr(game->wall[1].tex.img, &game->wall[1].tex.bpp,
			&game->wall[1].tex.line_length, &game->wall[1].tex.endian);
	game->wall[2].tex.addr
		= mlx_get_data_addr(game->wall[2].tex.img, &game->wall[2].tex.bpp,
			&game->wall[2].tex.line_length, &game->wall[2].tex.endian);
	game->wall[3].tex.addr
		= mlx_get_data_addr(game->wall[3].tex.img, &game->wall[3].tex.bpp,
			&game->wall[3].tex.line_length, &game->wall[3].tex.endian);
}

void	setup_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		(set_error(game, MLX), exit_cub3d(game));
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "R|D");
	if (!game->win)
		(set_error(game, MLX), exit_cub3d(game));
	init_images(game);
	init_data(game);
	init_animation_frames(game);
}
