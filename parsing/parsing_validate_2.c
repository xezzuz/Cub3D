/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:13:42 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 13:26:10 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	validate_doors(t_game *game, char **map)
{
	int		i;
	int		j;

	(void)game;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == DOOR)
			{
				if ((map[i][j + 1] == WALL && map[i][j - 1] == WALL))
					j++;
				else if (map[i + 1][j] == WALL && map[i - 1][j] == WALL)
					j++;
				else
					return (0);
			}
			else
				j++;
		}
		i++;
	}
	return (1);
}
