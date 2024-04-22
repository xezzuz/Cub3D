/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:38:17 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/22 17:06:11 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define	ERROR -42
#define	SUCCESS 1337

typedef struct s_texture
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		**ch_floor;
	char		**ch_ceiling;
	int			floor[3];
	int			ceiling[3];
}				t_texture;

typedef struct s_data
{
	char		**map;
	int			rows;
	int			columns;
}				t_data;

typedef struct s_game
{
	char		**map_cub;
	t_data		data;
	t_texture	textures;
}				t_game;


void	exit_cub3d(t_game *game, int flag);
void	free_2d(char **array);
size_t	array_size(char **array);
int		parsing(t_game *game, char *map_name);
void	struct_init(t_game *game);
int		map_extension(char *map_name);
int		read_config(t_game *game, char *map_name);
int		get_key_value(t_game *game, char **array);
int		get_rgb_colors(t_game *game);
int		validate_map(t_game *game);


size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);


void	ft_print_config(t_game *game, char *mapname);
