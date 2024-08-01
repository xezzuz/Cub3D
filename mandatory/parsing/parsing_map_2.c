/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:08:43 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 15:59:05 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	validate_spaces(char **map)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == EMPTY)
				if (!valid_left_right(map, i, j) || !valid_up_down(map, i, j))
					return (0);
		}
	}
	return (1);
}
