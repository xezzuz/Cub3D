/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:36:27 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/30 19:31:01 by nazouz           ###   ########.fr       */
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

# define TILE_SIZE 64
# define COLS 25
# define ROWS 9
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE
# define FOV 60 * (M_PI / 180)
# define WALL_COL_WIDTH 3

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

typedef struct s_line
{
	float		dx;
	float		dy;
	float		m;
	float		steps;
	float		x_inc;
	float		y_inc;
}				t_line;

typedef struct s_coords
{
	int			x;
	int			y;
}				t_coords;

typedef struct s_player
{
	t_coords	coords;
	int			radius;
	int			turnDirection;
	int			walkDirection;
	double		startingAngle;
	double		rotationAngle;
	double		moveSpeed;
	float		rotationSpeed;
}				t_player;

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
	t_coords	mapos;
	t_data		data;
	t_player	bob;
}				t_game;

void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
void	render_game(t_game	*game);
void	update(t_game *game);
void	update_player(t_game *game);
void	render_fov(t_game *game);

int		keypress(int key, t_game *game);
int		keyrelease(int key, t_game *game);

void	draw_circle(t_game *game);
void	draw_line(t_game *game, int z, t_coords a, t_coords b, int color);
void	draw_rect(t_game *game, t_coords start, int width, int height, int color);
void	draw_column(t_game *game, int x, double ray_length);

#endif
