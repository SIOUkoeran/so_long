/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:25:55 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/07 16:34:28 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(int fd)
{
	char	*map_temp;
	char	*temp;
	
	temp = get_next_line(fd);
	if (!temp)
		memory_exception();
	while (temp)
	{
		if (!map_temp)
			map_temp = ft_strdup(map_temp, temp);
		else
			map_temp = ft_strjoin(map_temp, temp);
		if (!map_temp)
			memory_exception();
		temp = get_next_line(fd);
	}
	free(temp);
	map_temp = ft_split(map_temp, '\n');
	return (map_temp);
}