/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaila <mmaila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:36:27 by nazouz            #+#    #+#             */
/*   Updated: 2024/07/31 11:42:35 by mmaila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>

# define ERROR -1
# define SUCCESS 1
# define BUFFER_SIZE 5
# define ARGC "Use: ./Cub3D <map_path>"
# define FNF "Cannot Open Config File :("
# define ALLOC "Allocation Failed :("
# define TXT "Textures / Colors are not Valid :("
# define MAP "Map is not Valid :("

# define WALL '1'
# define FLOOR '0'
# define NORTH 'N'
# define SOUTH 'S'
# define WEST 'W'
# define EAST 'E'
# define EMPTY ' '
# define DOOR 'D'

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define TILE 64
# define FOV (M_PI / 3)
# define NUM_OF_RAYS WIN_WIDTH

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define SPACE 49
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
	int		x;
	int		y;
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
	t_hitbox	box;
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
	int			doorh;
	int			doorv;
	int			door;
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
	t_frame	doortex;
	int		height;
	int		width;
	int		offset;
	int		y_txt;
}			t_tex;

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

typedef struct s_texture
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	unsigned int	fl;
	unsigned int	ceil;
	int				floor[3];
	int				ceiling[3];
}				t_texture;

typedef struct s_parse
{
	char		**file;
	char		**tex_colors;
	int			p_count;
	char		*err;
}				t_parse;

typedef struct	s_door
{
	t_coords	coords;
	int			closed;
}				t_door;

typedef struct s_map
{
	char	**map;
	t_door	*doors;
	int		dcount;
	int		rows;
	int		columns;
	int		height;
	int		width;

}				t_map;


typedef struct s_game
{
	t_map		lvl;
	t_ray		rays[NUM_OF_RAYS];
	t_player	bob;
	t_tex		wall;
	t_frame		frame;
	t_parse		parse;
	t_texture	textures;
	void		*mlx;
	void		*win;
	// t_weapon	gun;
	int			counter;
	int			animate;
	float		mouse_angle;
	void		*currframe;
}				t_game;

void	setup_init(t_game *game);

void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		get_pixel_color(t_frame *wall, int x, int y);

int		doorcheck(t_map *lvl, int x, int y);
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
















int		exit_cub3d(t_game *game);
void	free_2d(char **array);
size_t	array_size(char **array);
int		parsing(t_game *game, char *map_name);
void	struct_init(t_game *game);
int		map_extension(char *map_name);
int		read_config(t_game *game, char *map_name);
int		get_key_value(t_game *game, char **array, int i);
int		parse_colors(t_game *game, char *str, char key);
int		get_rgb_colors(t_game *game);
int		validate_map(t_game *game);
int		validate_surr_ends(char **map, int rows);
int		valid_up_down(char **map, size_t i, size_t j);
int		valid_left_right(char **map, size_t i, size_t j);
int		validate_doors(t_game *game, char **map);
int		map_is_rect(t_game *game);
int		fill_map_ends(t_game *game);
int		map_is_done(char **map, int i);
void	init_bob(t_game *game, int i, int j, char direction);
int		config_exist(t_game *game);
int		open_textures(t_game *game);
void	count_rows_cols(t_game *game);
int		count_commas(char *str);
void	set_error(t_game *game, char *error);
void	print_stderr(char *error);

int		add_to_array(char ***array, char *str);

int		str_is_empty(char *str);

size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);

void	ft_print_config(t_game *game);

#endif
