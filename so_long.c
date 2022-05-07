/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:36:57 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/07 18:43:41 by mkim3            ###   ########.fr       */
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

int main(int args, char **argv)
{
	t_map_info map_info;
	
	if (args != 2)
		exception();
	ft_check_file_name_extension(argv[1]);
	map_info.fd = open(argv[1]);
	if (map_info.fd < 0)
		exception();
	map_info.map = ft_read_map(map_info.fd);
	if (!map_info.map)
		map_exception();
}