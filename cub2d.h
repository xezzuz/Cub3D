/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:36:27 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/27 12:08:59 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB2D_H
# define CUB2D_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TILE_SIZE 64
# define COLS 25
# define ROWS 18
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE
# define FOV (M_PI / 3)
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
# define MOUSE 7

# define WHITE 0xffffff
# define BLACK 0x000000
# define RED 0xff0000
# define GRAY 0xC0C0C0


typedef struct s_coords
{
	int	x;
	int	y;
}				t_coords;

typedef struct s_fcoords
{
	float	x;
	float	y;
}				t_fcoords;

// typedef struct s_line
// {
// 	t_coords	intersection;
// 	int			dx;
// 	int			dy;
// 	int			stepx;
// 	int			stepy;
// 	int			err;
// 	int			e2;
// }				t_line;

typedef struct s_hitbox
{
	t_coords	up;
	t_coords	left;
	t_coords	right;
	t_coords	down;
}				t_hitbox;

typedef struct s_player
{
	t_hitbox	radius;
	t_coords	coords;
	int			turnDirection;
	int			upright;
	int			sideways;
	float		startingAngle;
	float		rotationAngle;
	float		moveSpeed;
	float		rotationSpeed;
	float		dppp;
}				t_player;

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_frame;

typedef struct s_ray
{
	t_fcoords	endpoint;
	float		ray_angle;
	float		distance;
	float		wall_height;
	int			horizontal;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_ray;

typedef struct s_texture
{
	t_frame	texture;
	int		height;
	int		width;
	int		x_offset;
	int		y_offset;
}			t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_frame		frame;
}				t_data;

typedef struct s_weapon
{
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
	void	*frame5;
	void	*frame6;
	void	*frame7;
	void	*frame8;
	void	*frame9;
	void	*frame10;
	void	*frame11;
	void	*frame12;
	int		width;
	int		height;
	int		count;
}			t_weapon;

typedef struct s_game
{
	char		**map;
	t_ray		rays[NUM_OF_RAYS];
	t_data		data;
	t_player	bob;
	t_texture	wall;
	t_weapon	gun;
	int			counter;
	int			animate;
	void		*currframe;
	int			mouse_hide;
}				t_game;

void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		render_game(t_game	*game);
void	update_game(t_game *game);
void	update_player(t_game *game);

int		keypress(int key, t_game *game);
int		keyrelease(int key, t_game *game);
int		mousemove(int x, int y, t_game *game);

void	draw_rect(t_game *game, t_coords start, int width, int height, int color);
void	render_walls(t_game *game);
void	render_minimap(t_game *game);

#endif
