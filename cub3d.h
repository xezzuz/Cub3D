/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:36:27 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/29 13:42:05 by mmaila           ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TILE 64
# define COLS 25
# define ROWS 18
# define WIDTH COLS * TILE
# define HEIGHT ROWS * TILE
# define FOV (M_PI / 3)
# define NUM_OF_RAYS WIN_WIDTH

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
# define GRAY 0xCFCFCF


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
	int			turn_dir;
	int			upright;
	int			sideways;
	float		startingAngle;
	float		rot_angle;
	float		moveSpeed;
	float		rot_speed;
	float		dppp;
}				t_player;

//bits per pixel > bpp
typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_frame;

typedef struct s_ray
{
	t_fcoords	endpoint;
	float		angle;
	float		dis;
	float		wall_height;
	int			horiz;
	int			down;
	int			right;
}				t_ray;

typedef struct s_tex
{
	t_frame	tex;
	t_frame	tex1;
	t_frame	tex2;
	t_frame	tex3;
	int		height;
	int		width;
	int		offset;
	int		y_txt;
}			t_tex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_frame		frame;
}				t_data;

// typedef struct s_weapon
// {
// 	void	*frame1;
// 	void	*frame2;
// 	void	*frame3;
// 	void	*frame4;
// 	void	*frame5;
// 	void	*frame6;
// 	void	*frame7;
// 	void	*frame8;
// 	void	*frame9;
// 	void	*frame10;
// 	void	*frame11;
// 	void	*frame12;
// 	int		width;
// 	int		height;
// 	int		count;
// }			t_weapon;

typedef struct s_game
{
	char		**map;
	t_ray		rays[NUM_OF_RAYS];
	t_player	bob;
	t_tex		wall;
	t_frame		frame;
	void		*mlx;
	void		*win;
	// t_weapon	gun;
	int			counter;
	int			animate;
	float		mouse_angle;
	void		*currframe;
}				t_game;

void	setup_init(t_game *game, char **map);

void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		get_pixel_color(t_frame *wall, int x, int y);

float	distance(t_coords a, t_fcoords b);
int		render_game(t_game	*game);
void	calc_hit(t_game *game, t_ray *ray);
void	cast_rays(t_game *game);
void	update_player(t_game *game);

int		keypress(int key, t_game *game);
int		keyrelease(int key, t_game *game);
int		mouse_move(int x, int y, t_game *game);

void	draw_rect(t_game *game, t_coords start, int width, int height, int color);
void	render_walls(t_game *game);
void	render_minimap(t_game *game);

#endif
