/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:18:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/26 16:22:42 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int keypress(int key, t_game *game)
{
	if (key == UP)
	{
		game->bob.walkDirection = 1;
		render_game(game);
	}
	else if (key == LEFT)
	{
		game->bob.turnDirection = -1;
		render_game(game);
	}
	else if (key == DOWN)
	{
		game->bob.walkDirection = -1;
		render_game(game);
	}
	else if (key == RIGHT)
	{
		game->bob.turnDirection = 1;
		render_game(game);
	}
	return (0);
}

int	keyrelease(int key, t_game *game)
{
	if (key == UP)
	{
		game->bob.walkDirection = 0;
		render_game(game);
	}
	else if (key == LEFT)
	{
		game->bob.turnDirection = 0;
		render_game(game);
	}
	else if (key == DOWN)
	{
		game->bob.walkDirection = 0;
		render_game(game);
	}
	else if (key == RIGHT)
	{
		game->bob.turnDirection = 0;
		render_game(game);
	}
	return (0);
}
