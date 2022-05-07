/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:12:38 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/07 18:38:48 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exception()
{
	write(2, "parsing_exception\n", 18);
	exit(1);
}

void	memory_exception()
{
	write(2, "memory_exception\n", 17);
	exit(1);
}

void map_exception()
{
	write(2, "Error\n", 6);
	exit(1);
}