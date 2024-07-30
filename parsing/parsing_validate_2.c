/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:13:42 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 17:04:23 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

t_door	*alloc_doors(char **map)
{
	int		i;
	int		j;
	int		count;
	t_door	*doors;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
				count++;
			j++;
		}
		i++;
	}
	doors = (t_door *) malloc((count * sizeof(t_door)));
	return (doors);
}

int	validate_doors(t_game *game, char **map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	game->lvl.doors = alloc_doors(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == DOOR)
			{
				if ((map[i][j + 1] != WALL || map[i][j - 1] != WALL)
					&& (map[i + 1][j] != WALL || map[i - 1][j] != WALL))
					return (0);
				game->lvl.doors[k].closed = 1;
				game->lvl.doors[k].coords.x = j;
				game->lvl.doors[k].coords.y = i;
				k++;
			}
			// {
			// 	if ((map[i][j + 1] == WALL && map[i][j - 1] == WALL))
			// 		j++;
			// 	else if (map[i + 1][j] == WALL && map[i - 1][j] == WALL)
			// 		j++;
			// 	else
			// 		return (0);
			// }
			// else
			j++;
		}
		i++;
	}
	game->lvl.dcount = k;
	return (1);
}
