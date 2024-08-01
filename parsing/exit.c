/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:41:58 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/01 10:57:04 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

size_t	array_size(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

void	free_2d(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	set_error(t_game *game, char *error)
{
	game->parse.err = error;
}

void	print_stderr(char *error)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
}

int	exit_cub3d(t_game *game)
{
	free_mlx(game);
	free_2d(game->lvl.map);
	free_2d(game->parse.file);
	free(game->parse.tex_colors);
	free(game->textures.north);
	free(game->textures.south);
	free(game->textures.west);
	free(game->textures.east);
	free(game->lvl.doors);
	if (game->parse.err)
		print_stderr(game->parse.err);
	return (exit(0), 0);
}
