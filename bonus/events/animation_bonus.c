/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 19:48:29 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/08 14:54:11 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

char	*get_frame_name(int frame_num)
{
	char	*number;
	char	*temp;
	char	*result;

	number = ft_itoa(frame_num);
	temp = ft_strjoin("./bonus/sprites/F", number);
	free(number);
	result = ft_strjoin(temp, ".xpm");
	free(temp);
	return (result);
}

int	init_animation_frames(t_game *game)
{
	int			i;
	int			x;
	int			fd;
	char		*frame_name;

	i = 0;
	game->current_frame = 0;
	while (i < NUM_FRAMES)
	{
		frame_name = get_frame_name(i);
		if (!frame_name)
			(set_error(game, ALLOC), exit_cub3d(game));
		fd = open(frame_name, O_RDONLY);
		if (fd == -1)
			return (free(frame_name), set_error(game, TXT), exit_cub3d(game));
		game->animation[i++]
			= mlx_xpm_file_to_image(game->mlx, frame_name, &x, &x);
		free(frame_name);
	}
	return (1);
}

void	display_animation_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->animation[game->current_frame], (WIN_WIDTH / 2) - 540, 0);
	if (game->current_frame >= NUM_FRAMES - 1)
		game->current_frame = 0;
	else
		game->current_frame++;
}
