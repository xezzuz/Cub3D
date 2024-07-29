/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:38:04 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/29 17:29:37 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2 || !parsing(&game, argv[1]))
	{
		printf("Error\n");
		return (1);
	}
		// return (exit_cub3d(&game, ERROR), 1);
}
