/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:36:57 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/14 19:03:26 by mkim3            ###   ########.fr       */
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

static int	ft_key_event(int key, t_param s_param)
{
	static int	a = 0;

	if (key == W)
		s_param.y++;
	else if (key == A)
		s_param.x--;
	else if (key == S)
		s_param.y--;
	else if (key == D)
		s_param.x++;
	return (0);
}

static void ft_set_image(t_map_info s_map_info, void *mlx, void *win, t_game_info game_info)
{
	int	i;
	int	j;

	i = -1;
	while (	s_map_info.map[++i])
	{
		j = -1;
		while (s_map_info.map[i][++j])
		{
			printf("%d %d \n", i, j);
			if (s_map_info.map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, game_info.img_wall, j * 64, i * 64);
			else if (s_map_info.map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, game_info.img_character, j * 64, i * 64);
			else if (s_map_info.map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, game_info.img_wall, j * 64, i * 64);
			else if (s_map_info.map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, game_info.img_item, j * 64, i * 64);
		}
	}
}

static t_game_info	ft_insert_game_info(void *mlx, t_game_info game_info)
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
	game_info = ft_insert_game_info(mlx, game_info);
	ft_set_image(map_info, mlx, win, game_info);
	mlx_hook(win, EVENT_KEY_RELEASE, 0, &ft_key_event, &param);
	mlx_loop(mlx);
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