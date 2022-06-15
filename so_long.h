/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:37:12 by mkim3             #+#    #+#             */
/*   Updated: 2022/06/15 20:29:00 by mkim3            ###   ########.fr       */
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
# define ESC 53
# define EVENT_KEY 2
# define EVENT_KEY_RELEASE 3
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx_opengl_20191021/mlx.h"

typedef struct s_check_map {
	int	e;
	int	c;
	int	p;
	int	wall;
	int	road;
}	t_check_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map_info {
	char	**map;
	int		fd;
	int		height;
	int		width;
	int		item_cnt;
}	t_map_info;

typedef struct s_param {
	int	x;
	int	y;
}	t_param;

typedef struct s_game_info {
	void	*img_w;
	void	*img_r;
	void	*img_i;
	void	*img_c;
	void	*img_e;
	void	*m;
	void	*w;
	int		item_cnt;
	int		x;
	int		y;
	int		height;
	int		width;
	int		walks;
	char	**map;
}	t_game_info;

typedef struct s_character_info {
	int	walk_cnt;
	int	item;
}	t_character_info;

void		exception(void);
void		memory_exception(void);
void		map_exception(void);
t_map_info	ft_read_map(int fd);
void		ft_check_map(char **map, t_map_info *map_info);
void		ft_set_image(t_game_info *game_info);
void		move(t_game_info *game_info, int next_x, int next_y);
void		ft_set_image_64pixel(t_game_info *s, int x, int y, char c);
int			ft_key_event(int key, t_game_info *game_info);
void		ft_insert_map_info(int r, int c, t_map_info *m, t_check_map cm);
void		ft_free_game_info(t_game_info *game_info);
int			ft_close(t_game_info *g);
#endif
