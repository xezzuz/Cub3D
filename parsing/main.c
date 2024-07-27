/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:38:04 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 18:07:27 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2 || !parsing(&game, argv[1]))
		return (1);
		// return (exit_cub3d(&game, ERROR), 1);
}
