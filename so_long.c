/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:36:57 by mkim3             #+#    #+#             */
/*   Updated: 2022/06/15 20:28:14 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_file_name_extension(char *file_name)
{
	int	idx;

	idx = -1;
	while (file_name[++idx])
		if (file_name[idx] == '.')
			break ;
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

static t_game_info	ft_insert(t_map_info m, void *mlx, t_game_info g, void *w)
{
	int	width;
	int	height;

	g.img_r = mlx_xpm_file_to_image(mlx, "./image/road.xpm"\
	, &width, &height);
	g.img_w = mlx_xpm_file_to_image(mlx, "./image/wall.xpm"\
	, &width, &height);
	g.img_c = mlx_xpm_file_to_image(mlx, "./image/character.xpm"\
	, &width, &height);
	g.img_i = mlx_xpm_file_to_image(mlx, "./image/item.xpm"\
	, &width, &height);
	g.img_e = mlx_xpm_file_to_image(mlx, "./image/exit.xpm"\
	, &width, &height);
	g.m = mlx;
	g.w = w;
	g.map = m.map;
	g.item_cnt = m.item_cnt;
	g.height = m.height;
	g.width = m.width;
	g.walks = 1;
	return (g);
}

static void	ft_display_map(t_map_info m)
{
	void		*mlx;
	void		*win;
	t_param		param;
	t_game_info	game_info;

	mlx = mlx_init();
	win = mlx_new_window(mlx, m.width * 64, m.height * 64, "so_long");
	game_info = ft_insert(m, mlx, game_info, win);
	ft_set_image(&game_info);
	mlx_hook(win, EVENT_KEY_RELEASE, 0, ft_key_event, &game_info);
	mlx_hook(win, 17, 0, ft_close, &game_info);
	mlx_loop(mlx);
}

int	main(int args, char **argv)
{
	t_map_info	map_info;

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
	return (0);
}
