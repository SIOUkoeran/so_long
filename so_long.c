/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:36:57 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/14 20:50:59 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

static void ft_check_file_name_extension(char *file_name)
{
	int	idx = -1;
	while (file_name[++idx])
		if (file_name[idx] == '.')
			break;
	if (file_name[++idx] != 'b')
		map_exception();
	if (file_name[++idx] != 'e')
		map_exception();
	if (file_name[++idx] != 'r')
		map_exception();
	if (file_name[++idx] != '\0')
		map_exception();
}

static void	ft_set_game_info(t_map_info *s_map_info, t_game_info *game_info)
{
	game_info->item_cnt = s_map_info->item_cnt;
	game_info->height = s_map_info->height;
	game_info->width = s_map_info->width;
	game_info->map = s_map_info->map;
}

static t_game_info	ft_insert_game_info(t_map_info map_info, void *mlx, t_game_info game_info, void *win)
{
	int width;
	int height;
	
	game_info.img_road = mlx_xpm_file_to_image(mlx, "./image/road.xpm"\
	, &width, &height);
	game_info.img_wall = mlx_xpm_file_to_image(mlx, "./image/wall.xpm"\
	, &width, &height);
	game_info.img_character = mlx_xpm_file_to_image(mlx, "./image/character.xpm"\
	, &width, &height);
	game_info.img_item = mlx_xpm_file_to_image(mlx, "./image/item.xpm"\
	, &width, &height);
	game_info.img_exit = mlx_xpm_file_to_image(mlx, "./image/exit.xpm"\
	, &width, &height);
	game_info.mlx = mlx;
	game_info.win = win;
	game_info.map = map_info.map;
	game_info.item_cnt = map_info.item_cnt;
	game_info.height = map_info.height;
	game_info.width = map_info.width;
	game_info.walks = 1;
	return (game_info);
}

static void ft_display_map(t_map_info map_info)
{
	void		*mlx;
	void		*win;
	t_param		param;
	t_game_info game_info;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx ,map_info.width* 64, map_info.height * 64, "so_long");
	game_info = ft_insert_game_info(map_info, mlx, game_info, win);
	ft_set_image(&game_info);
	mlx_hook(win, EVENT_KEY_RELEASE, 0, &ft_key_event, &game_info);
	mlx_loop(mlx);
	free(mlx);
	free(win);
}

int main(int args, char **argv)
{
	t_map_info map_info;

	char temp[100];
	if (args != 2)
		exception();
	ft_check_file_name_extension(argv[1]);
	map_info.fd = open(argv[1], O_RDONLY);
	if (map_info.fd < 0)
		exception();
	map_info = ft_read_map(map_info.fd);
	if (!map_info.map)
		map_exception();
	ft_display_map(map_info);
}