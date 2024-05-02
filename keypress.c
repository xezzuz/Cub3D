/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:18:30 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/02 21:28:14 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub2d.h"

int keypress(int key, t_game *game)
{
	if (key == UP)
		game->bob.walkDirection = 1;
	else if (key == LEFT)
		game->bob.turnDirection = -1;
	else if (key == DOWN)
		game->bob.walkDirection = -1;
	else if (key == RIGHT)
		game->bob.turnDirection = 1;
	return (0);
}

int	keyrelease(int key, t_game *game)
{
	if (key == UP)
		game->bob.walkDirection = 0;
	else if (key == LEFT)
		game->bob.turnDirection = 0;
	else if (key == DOWN)
		game->bob.walkDirection = 0;
	else if (key == RIGHT)
		game->bob.turnDirection = 0;
	return (0);
}
