/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:14:35 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 22:04:23 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	size_t				i;
	unsigned char		*temp;

	temp = (unsigned char *) buf;
	i = 0;
	while (i < count)
	{
		if (temp[i] == (unsigned char)c)
		{
			return (temp + i);
		}
		i++;
	}
	return (0);
}
