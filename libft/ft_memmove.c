/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:46:48 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 21:54:43 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{	
	if (src >= dest)
		return (ft_memcpy(dest, src, len));
	while (len > 0)
	{
		len--;
		((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
	}
	return (dest);
}
