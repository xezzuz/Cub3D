/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/26 17:39:52 by nazouz           ###   ########.fr       */
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
	game->data.win = mlx_new_window(game->data.mlx, COLS * TILE_SIZE, ROWS * TILE_SIZE, "RED");
	if (!game->data.win)
		exit(1);
	game->map = map;
	game->data.img = mlx_new_image(game->data.mlx, WIDTH, HEIGHT);
	game->data.addr = mlx_get_data_addr(game->data.img, &game->data.bits_per_pixel, &game->data.line_length, &game->data.endian);
	game->bob.coords.x = (19 * TILE_SIZE) + TILE_SIZE / 2;
	game->bob.coords.y = (4 * TILE_SIZE) + TILE_SIZE / 2;
	game->bob.turnDirection = 0; // -1 left, 1 right
	game->bob.walkDirection = 0; // -1 back, 1 front
	game->bob.startingAngle = M_PI_2;
	game->bob.rotationAngle = game->bob.startingAngle;
	game->bob.moveSpeed = 8.0;
	game->bob.rotationSpeed = 5 * (M_PI / 180);
	game->bob.radius = 3;
}

int main(void)
{
	t_game		game;

	char	*map[7] = {
        "1111111111111111111111111",
        "1000000000110000000000001",
        "1011000001110000000000001",
        "1001000000000000000000001",
        "1100010101101001111N00001",
        "1111011111101011011110101",
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
	setup_init(&game, map);
	render_game(&game);
	mlx_hook(game.data.win, 2, 0, keypress, &game);
	mlx_hook(game.data.win, 3, 0, keyrelease, &game);
	mlx_loop(game.data.mlx);
	printf("FINISHED\n");
}
