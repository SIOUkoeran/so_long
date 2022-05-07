/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:36:57 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/07 18:15:32 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int args, char **argv)
{
	t_map_info map_info;
	
	if (args != 2)
		exception();
	map_info.fd = open(argv[1]);
	if (map_info.fd < 0)
		exception();
	map_info.map = ft_read_map(map_info.fd);
	if (!map_info.map)
		map_exception();
}