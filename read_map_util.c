/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:56:23 by mkim3             #+#    #+#             */
/*   Updated: 2022/06/15 20:33:13 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_insert_map_info(int r, int c, t_map_info *m, t_check_map cm)
{
	m->height = r;
	m->width = c;
	m->item_cnt = cm.c;
}

int	ft_close(t_game_info *g)
{
	ft_free_game_info(g);
	exit(0);
	return (0);
}
