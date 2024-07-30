/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_validate_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:13:42 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 15:44:17 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	validate_doors(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == DOOR)
				if ((map[i][j + 1] != WALL || map[i][j - 1] != WALL)
					&& (map[i + 1][j] != WALL || map[i - 1][j] != WALL))
					return (0);
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
	return (1);
}
