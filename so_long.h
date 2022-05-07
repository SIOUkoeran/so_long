/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 20:37:12 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/07 18:29:50 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ROWCHECK 1
# define COLCHECK 0
# include <stdlib.h>
# include <errno.h>

typedef struct s_check_map {
	int	e;
	int	c;
	int	p;
	int	wall;
	int	road;
} t_check_map;

typedef struct s_map_info {
	char	**map;
	int		fd;
} t_map_info;

void	exception();
void	memory_exception();
void	map_exception();
char	**ft_read_map(int fd);

#endif
