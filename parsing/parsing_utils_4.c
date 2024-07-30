/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:48:19 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/30 12:19:52 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	count_commas(char *str)
{
	int			i;
	int			comma;

	if (!str)
		return (0);
	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i++] == ',')
		{
			comma++;
			while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
				i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (0);
		}
	}
	return (comma == 2);
}

int	parse_colors(t_game *game, char *str, char key)
{
	int		i;
	int		num_counter;

	num_counter = 0;
	if (!count_commas(str))
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == key)
		i++;
	while (str[i])
	{
		if (num_counter == 3)
			return (0);
		if (key == 'C')
			game->textures.ceiling[num_counter++] = ft_atoi(&str[i]);
		else
			game->textures.floor[num_counter++] = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == ',')
			i++;
	}
	return (num_counter == 3);
}
