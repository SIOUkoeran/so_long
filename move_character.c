/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_character.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:13:02 by mkim3             #+#    #+#             */
/*   Updated: 2022/06/15 20:32:52 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_event(int key, t_game_info *game_info)
{
	char	**map;

	map = game_info->map;
	if (key == W && map[game_info->x - 1][game_info->y])
		move(game_info, game_info->x - 1, game_info->y);
	else if (key == A && map[game_info->x][game_info->y - 1])
		move(game_info, game_info->x, game_info->y - 1);
	else if (key == S && map[game_info->x + 1][game_info->y])
		move(game_info, game_info->x + 1, game_info->y);
	else if (key == D && map[game_info->x][game_info->y + 1])
		move(game_info, game_info->x, game_info->y + 1);
	else if (key == ESC)
		exit(0);
	return (0);
}

static void	ft_change_position(t_game_info *game_info, int next_x, int next_y)
{
	game_info->x = next_x;
	game_info->y = next_y;
}

static void	ft_move_character(t_game_info *game_info, int next_x, int next_y)
{
	game_info->map[next_x][next_y] = 'P';
	ft_set_image_64pixel(game_info, game_info->x, game_info->y, '0');
	game_info->map[game_info->x][game_info->y] = '0';
	ft_change_position(game_info, next_x, next_y);
}

void	ft_free_game_info(t_game_info *game_info)
{
	int	i;

	i = -1;
	mlx_destroy_window(game_info->m, game_info->w);
	while (game_info->map[++i])
	{
		free(game_info->map[i]);
	}
	free(game_info->map);
}

void	move(t_game_info *game_info, int next_x, int next_y)
{
	char	**map;

	map = game_info->map;
	if (map[next_x][next_y] == 1 || !map[next_x][next_y])
		return ;
	if (map[next_x][next_y] == 'C')
	{
		ft_move_character(game_info, next_x, next_y);
		game_info->item_cnt--;
		printf("이동 회수 : %d\n", game_info->walks++);
	}
	else if (map[next_x][next_y] == '0')
	{
		ft_move_character(game_info, next_x, next_y);
		printf("이동 회수 : %d\n", game_info->walks++);
	}
	else if (map[next_x][next_y] == 'E' && game_info->item_cnt == 0)
	{
		printf("이동 회수 : %d\n", game_info->walks++);
		ft_move_character(game_info, next_x, next_y);
		ft_free_game_info(game_info);
		exit(0);
	}
	ft_set_image(game_info);
}
