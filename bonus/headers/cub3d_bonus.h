/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:26:14 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/08 13:46:49 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <mlx.h>
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
# define MLX "MLX FAILED"

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
# define FOV 1.0471975512
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
# define X 7

# define NUM_FRAMES 9

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
	float		rot_angle;
	float		move_speed;
	float		rot_speed;
	float		dppp;
}				t_player;

typedef struct s_frame
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}			t_frame;

typedef struct s_ray
{
	t_fcoords	hit;
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
	int		offset;
	int		y_txt;
}			t_tex;

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

typedef struct s_door
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
	void		*mlx;
	void		*win;
	t_map		lvl;
	t_ray		rays[NUM_OF_RAYS];
	t_player	bob;
	t_tex		wall[5];
	t_frame		frame;
	t_parse		parse;
	t_texture	textures;
	int			mouse_mp;
	float		mouse_angle;
	int			mouse_hidden;
	void		*animation[NUM_FRAMES];
	int			current_frame;
}				t_game;

int		mlx_mouse_hide(void);
int		mlx_mouse_show(void);
int		mlx_mouse_move(void *win_ptr, int x, int y);

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
void	draw_rect(t_game *game, t_coords start, t_coords end, int color);
void	render_walls(t_game *game);
void	render_minimap(t_game *game);
int		exit_cub3d(t_game *game);
void	free_2d(char **array);
size_t	array_size(char **array);
int		parsing(t_game *game, char *map_name);
void	struct_init(t_game *game);
int		fill_struct(t_game *game);
int		fill_textures(t_game *game);
int		fill_map(t_game *game, int map_size);
int		validate_doors(t_game *game, char **map);
int		validate_spaces(char **map);
t_door	*alloc_doors(char **map);
int		map_extension(char *map_name);
int		read_config(t_game *game, char *map_name);
int		get_key_value(t_game *game, char **array, int i);
void	mouse_adjustement(t_game *game);
int		parse_colors(t_game *game, char *str, char key);
int		get_rgb_colors(t_game *game);
int		validate_map(t_game *game);
int		validate_surr_ends(char **map, int rows);
int		valid_up_down(char **map, size_t i, size_t j);
int		valid_left_right(char **map, size_t i, size_t j);
int		validate_doors(t_game *game, char **map);
int		map_is_rect(t_game *game);
void	free_mlx(t_game *game);
int		fill_map_ends(t_game *game);
int		map_is_done(char **map, int i);
void	init_bob(t_game *game, int i, int j, char direction);
int		config_exist(t_game *game);
int		open_textures(t_game *game);
void	count_rows_cols(t_game *game);
int		count_commas(char *str);
void	set_error(t_game *game, char *error);
void	print_stderr(char *error);
int		init_animation_frames(t_game *game);
void	display_animation_frame(t_game *game);
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
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);

#endif
