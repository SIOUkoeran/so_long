/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:36:57 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/09 21:31:02 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void ft_display_map(t_map_info map_info)
{
	void	*mlx_info;
	void	*mlx_win;
	t_data	data;
	
	mlx_info = mlx_init();
	mlx_win = mlx_new_window(mlx_info, 1920, 1080, "so_long");
	data.img = mlx_new_image(mlx_info, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	for (int i = 0; i < 100; i++){
		my_mlx_pixel_put(&data, i, i, 0x00FF0000);// 붉은색 선을 대각선으로 그린다.
		my_mlx_pixel_put(&data, 5, i, 0x00FF0000);// 붉은색 선을 세로으로 그린다.
		my_mlx_pixel_put(&data, i, 5, 0x00FF0000);// 붉은색 선을 가로으로 그린다.
	}
	mlx_put_image_to_window(mlx_info, mlx_win, data.img, 0, 0);//이미지를 윈도우에 올린다.
	mlx_loop(mlx_win);
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
	map_info.map = ft_read_map(map_info.fd);
	if (!map_info.map)
		map_exception();
	ft_display_map(map_info);
}