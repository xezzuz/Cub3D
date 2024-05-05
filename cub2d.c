/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/05 15:56:59 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->data.addr + (y * game->data.line_length + x * (game->data.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	game->data.img = mlx_new_image(game->data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img, &game->data.bits_per_pixel, &game->data.line_length, &game->data.endian);
	game->bob.coords.x = ((COLS / 2) * TILE_SIZE) + TILE_SIZE / 2;
	game->bob.coords.y = ((ROWS / 2) * TILE_SIZE) + TILE_SIZE / 2;
	game->mapos.x =  WIDTH / 6 - game->bob.coords.x;
	game->mapos.y = HEIGHT / 6 - game->bob.coords.y;
	game->bob.turnDirection = 0;
	game->bob.upright = 0;
	game->bob.sideways = 0;
	game->bob.startingAngle =  M_PI / 2;
	game->bob.rotationAngle = game->bob.startingAngle;
	game->bob.moveSpeed = 4.0;
	game->bob.rotationSpeed = 1 * (M_PI / 180);
	game->bob.radius = 3;
}

int main(void)
{
	t_game		game;

	// char	*map[18] = {
    //     "1111111111111111111111111",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000001000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1000000000000000000000001",
    //     "1111111111111111111111111"
    // };
	
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
	// char	*map[6] = {
	// 	"1111111111",
	// 	"1001001101",
	// 	"1100000001",
	// 	"1000000001",
	// 	"1001P01001",
	// 	"1111111111"
	// };
	// printf("Game Resolution: %dx%d\n\n", WIDTH, HEIGHT);
	setup_init(&game, map);
	game.player_x = COLS * 10 / 2;
	game.player_y = ROWS * 10 / 2;
	mlx_hook(game.data.win, 2, 0, keypress, &game);
	mlx_hook(game.data.win, 3, 0, keyrelease, &game);
	mlx_loop_hook(game.data.mlx, render_game, &game);
	mlx_loop(game.data.mlx);
	printf("FINISHED\n");
}
