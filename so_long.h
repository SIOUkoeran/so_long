/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:37:12 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/14 17:44:54 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ROWCHECK 1
# define COLCHECK 0
# define W 13
# define A 0
# define S 1
# define D 2
# define EVENT_KEY 2
# define EVENT_KEY_RELEASE 3
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include "get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"
typedef struct s_check_map {
	int	e;
	int	c;
	int	p;
	int	wall;
	int	road;
	int	height;
	int	weight;
} t_check_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_map_info {
	char	**map;
	int		fd;
} t_map_info;

typedef struct s_param {
	int	x;
	int	y;
} t_param;

typedef struct s_game_info {
	void *img_wall;
	void *img_road;
	void *img_item;
	void *img_character;
} t_game_info;
void	exception();
void	memory_exception();
void	map_exception();
char	**ft_read_map(int fd);
void	ft_check_map(char **map);
#endif
