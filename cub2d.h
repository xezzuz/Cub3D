/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:36:27 by nazouz            #+#    #+#             */
/*   Updated: 2024/05/05 13:50:05 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB2D_H
# define CUB2D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define TILE_SIZE 64
# define COLS 25
# define ROWS 18
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE
# define FOV 60 * (M_PI / 180)
# define WALL_COL_WIDTH 1
# define NUM_OF_RAYS WINDOW_WIDTH / WALL_COL_WIDTH

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# define WHITE 0xffffff
# define BLACK 0x000000
# define RED 0xff0000
# define GRAY 0xC0C0C0


typedef struct s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct s_line
{
	t_coords	intersection;
	int			dx;
	int			dy;
	int			stepx;
	int			stepy;
	int			err;
	int			e2;
}				t_line;

typedef struct s_player
{
	t_coords	coords;
	int			radius;
	int			turnDirection;
	int			upright;
	int			sideways;
	double		startingAngle;
	double		rotationAngle;
	double		moveSpeed;
	float		rotationSpeed;
}				t_player;


typedef struct s_ray
{
	t_coords	endpoint;
	double		distance;
}				t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_game
{
	char		**map;
	t_ray		rays[NUM_OF_RAYS];
	t_coords	mapos;
	t_data		data;
	t_player	bob;
	int			player_x;
	int			player_y;
}				t_game;

void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		render_game(t_game	*game);
void	update(t_game *game);
void	update_player(t_game *game);

int		keypress(int key, t_game *game);
int		keyrelease(int key, t_game *game);

void	draw_rect(t_game *game, t_coords start, int width, int height, int color);
void	render_walls(t_game *game);

#endif
