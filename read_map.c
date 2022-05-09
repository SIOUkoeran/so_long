/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:25:55 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/09 20:04:01 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_check_wall(char *map, int flag, char position)
{
	int	idx;

	idx = -1;
	if (flag)
	{
		while (map[++idx])
			if (map[idx] != '1')
				map_exception();
	}
	else
		if (position != '1')
			map_exception();
}

static t_check_map	count_map_info(t_check_map info, char c)
{
	if (c == 'C')
		info.c++;
	else if (c == 'P')
		info.p++;
	else if (c == 'E')
		info.e++;
	else if (c == '1')
		info.wall++;
	else if (c == '0')
		info.road++;
	else
		map_exception();
	return (info);
}

static void	check_map_info(t_check_map info)
{
	if (info.c < 1)
		map_exception();
	if (info.e < 1)
		map_exception();
	if (info.p != 1)
		map_exception();
}

void	ft_check_map(char **map)
{
	t_check_map	map_info;
	int			col_idx;
	int			row_idx;
	int			col_length;

	row_idx = -1;
	ft_memset(&map_info, 0, sizeof(t_check_map));
	if (!map)
		memory_exception();
	col_length = ft_strlen(map[0]);
	ft_check_wall(map[0], ROWCHECK, '1');
	while (map[++row_idx])
	{
		col_idx = 0;
		ft_check_wall(map[row_idx], COLCHECK, map[row_idx][col_idx]);
		while (map[row_idx][col_idx])
			map_info = count_map_info(map_info, map[row_idx][col_idx++]);
		if (col_idx != col_length)
			map_exception();
		ft_check_wall(map[row_idx], COLCHECK, map[row_idx][col_idx - 1]);
	}
	ft_check_wall(map[row_idx - 1], ROWCHECK, '1');
	check_map_info(map_info);
}

char	**ft_read_map(int fd)
{
	char	*map_temp;
	char	*temp;
	char	**map;

	temp = get_next_line(fd);
	map_temp = NULL;
	if (!temp)
		memory_exception();
	while (temp)
	{
		if (!map_temp)
			map_temp = ft_strdup(temp);
		else
			map_temp = ft_strjoin(map_temp, temp);
		if (!map_temp)
			memory_exception();
		temp = get_next_line(fd);
	}
	map = ft_split(map_temp, '\n');
	ft_check_map(map);
	return (map);
}