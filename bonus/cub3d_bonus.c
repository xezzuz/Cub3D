/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:34:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 16:10:57 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (print_stderr(ARGC), 1);
	if (!parsing(&game, argv[1]))
		return (exit_cub3d(&game), 1);
	setup_init(&game);
	mlx_hook(game.win, 2, 0, keypress, &game);
	mlx_hook(game.win, 3, 0, keyrelease, &game);
	mlx_hook(game.win, 6, 0, mouse_move, &game);
	mlx_hook(game.win, 17, 0, exit_cub3d, &game);
	mlx_loop_hook(game.mlx, render_game, &game);
	mlx_loop(game.mlx);
	exit_cub3d(&game);
}
