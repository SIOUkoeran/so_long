/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:55:54 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/14 20:10:41 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_set_image(t_game_info *game_info)
{
	int	i;
	int	j;

	i = -1;
	while (game_info->map[++i])
	{
		j = -1;
		while (game_info->map[i][++j])
		{
			if (game_info->map[i][j] == '1')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img_wall, j * 64, i * 64);
			else if (game_info->map[i][j] == 'P')
			{
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img_character, j * 64, i * 64);
				game_info->x = i;
				game_info->y = j;
			}
			else if (game_info->map[i][j] == 'E')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img_exit, j * 64, i * 64);
			else if (game_info->map[i][j] == 'C')
				mlx_put_image_to_window(game_info->mlx, game_info->win, game_info->img_item, j * 64, i * 64);
		}
	}
}

void ft_set_image_64pixel(t_game_info *s_game_info, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(s_game_info->mlx, s_game_info->win, s_game_info->img_wall, y * 64, x * 64);
	else if (c == '0')
		mlx_put_image_to_window(s_game_info->mlx, s_game_info->win, s_game_info->img_road, y * 64, x * 64);
	else if (c == 'P')
		mlx_put_image_to_window(s_game_info->mlx, s_game_info->win, s_game_info->img_character, y * 64, x * 64);
}
