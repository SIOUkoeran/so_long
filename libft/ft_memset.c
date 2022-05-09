/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:50:02 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/02 13:19:23 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t num)
{
	size_t			i;
	unsigned char	*temp;

	temp = p;
	i = 0;
	while (i < num)
	{
		temp[i] = value;
		i++;
	}
	return (temp);
}
