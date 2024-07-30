/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 15:22:07 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d.h"

void	ff()
{
	system("leaks Cub3D");
}

int	main(int argc, char **argv)
{
	t_game		game;

	atexit(ff);
	if (argc != 2 || !parsing(&game, argv[1]))
	{
		printf("Error\n"); // stderr
		return (1);
	}
	setup_init(&game);
	mlx_hook(game.win, 2, 0, keypress, &game);
	mlx_hook(game.win, 3, 0, keyrelease, &game);
	mlx_hook(game.win, 6, 0, mouse_move, &game);
	mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.mlx);
}
