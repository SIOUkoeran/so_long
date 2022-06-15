/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:55:54 by mkim3             #+#    #+#             */
/*   Updated: 2022/06/15 18:04:54 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_image(t_game_info *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->m, g->w, g->img_w, j * 64, i * 64);
			else if (g->map[i][j] == 'P')
			{
				mlx_put_image_to_window(g->m, g->w, g->img_c, j * 64, i * 64);
				g->x = i;
				g->y = j;
			}
			else if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->m, g->w, g->img_e, j * 64, i * 64);
			else if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->m, g->w, g->img_i, j * 64, i * 64);
		}
	}
}

void	ft_set_image_64pixel(t_game_info *g, int x, int y, char c)
{
	if (c == '1')
		mlx_put_image_to_window(g->m, g->w, g->img_w, y * 64, x * 64);
	else if (c == '0')
		mlx_put_image_to_window(g->m, g->w, g->img_r, y * 64, x * 64);
	else if (c == 'P')
		mlx_put_image_to_window(g->m, g->w, g->img_c, y * 64, x * 64);
}
