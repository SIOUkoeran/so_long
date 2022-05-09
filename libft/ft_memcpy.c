/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:36:13 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/05 13:25:32 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	size_t					i;
	unsigned char			*temp_dst;
	const unsigned char		*temp_src;

	i = 0;
	temp_dst = dest;
	temp_src = source;
	if (dest == (void *)0 && source == (void *)0)
		return (dest);
	while (i < num)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dest);
}
