/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/28 11:39:32 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data.frame.addr + (y * game->data.frame.line_length + x * (game->data.frame.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float	rotation(char angle)
{
	if (angle == 'N')
		return ((M_PI * 3.0) / 2.0);
	else if (angle == 'S')
		return (M_PI / 2.0);
	else if (angle == 'E')
		return (0);
	return (M_PI);
}

void	setup_init(t_game *game, char *map[])
{
	game->data.mlx = mlx_init();
	if (!game->data.mlx)
		exit(1);
	game->data.win = mlx_new_window(game->data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "R|D");
	if (!game->data.win)
		exit(1);
	game->map = map;
	game->counter = 0;
	game->animate = 0;
	game->wall.texture.img = mlx_xpm_file_to_image(game->data.mlx, "textures/pokerheart", &game->wall.width, &game->wall.height);
	game->wall.texture1.img = mlx_xpm_file_to_image(game->data.mlx, "textures/pokerspades", &game->wall.width, &game->wall.height);
	game->wall.texture2.img = mlx_xpm_file_to_image(game->data.mlx, "textures/pokerclubs", &game->wall.width, &game->wall.height);
	game->wall.texture3.img = mlx_xpm_file_to_image(game->data.mlx, "textures/pokerdiamond", &game->wall.width, &game->wall.height);
	game->wall.texture.addr = mlx_get_data_addr(game->wall.texture.img, &game->wall.texture.bits_per_pixel, &game->wall.texture.line_length, &game->wall.texture.endian);
	game->wall.texture1.addr = mlx_get_data_addr(game->wall.texture1.img, &game->wall.texture1.bits_per_pixel, &game->wall.texture1.line_length, &game->wall.texture1.endian);
	game->wall.texture2.addr = mlx_get_data_addr(game->wall.texture2.img, &game->wall.texture2.bits_per_pixel, &game->wall.texture2.line_length, &game->wall.texture2.endian);
	game->wall.texture3.addr = mlx_get_data_addr(game->wall.texture3.img, &game->wall.texture3.bits_per_pixel, &game->wall.texture3.line_length, &game->wall.texture3.endian);
	game->data.frame.img = mlx_new_image(game->data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->data.frame.addr = mlx_get_data_addr(game->data.frame.img, &game->data.frame.bits_per_pixel, &game->data.frame.line_length, &game->data.frame.endian);
	game->bob.coords.x = (21 * TILE_SIZE) + TILE_SIZE / 2;
	game->bob.coords.y = (4 * TILE_SIZE) + TILE_SIZE / 2;
	game->bob.turnDirection = 0;
	game->bob.upright = 0;
	game->bob.sideways = 0;
	game->bob.startingAngle = rotation('S');
	game->bob.rotationAngle = game->bob.startingAngle;
	game->bob.moveSpeed = 4.0;
	game->bob.rotationSpeed = 1 * (M_PI / 180);
	game->bob.dppp = ((WINDOW_WIDTH) / 2) / tan(FOV / 2);
	game->mouse_angle = 0;
	mlx_mouse_hide();
}

int main(void)
{
	t_game		game;

	char	*map[18] = {
        "1111111111111111111111111",
        "1000000000110000000000001",
        "1011000001110000000000001",
        "1000000000000000000000001",
        "1100010101101001111N00001",
        "1101011111101011011110101",
        "1001011111101011000000101",
        "1001000000001000011110001",
		"1101011111101011011110101",
        "1001011111100011000000101",
        "1001000000000000011110001",
		"1101011011100011011110101",
        "1001011001101011000000101",
        "1001000000000000011010001",
		"1101011111001011011010101",
        "1001011100001011000000101",
        "1001000000000000011110001",
        "1111111111111111111111111"
    };

	setup_init(&game, map);
	mlx_hook(game.data.win, 2, 0, keypress, &game);
	mlx_hook(game.data.win, 3, 0, keyrelease, &game);
	mlx_hook(game.data.win, 6, 0, mouse_move, &game);
	mlx_loop_hook(game.data.mlx, render_game, &game);
	mlx_loop(game.data.mlx);
}
