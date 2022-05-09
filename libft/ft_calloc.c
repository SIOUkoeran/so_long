/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:08:12 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 21:53:57 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	i;

	i = 0;
	temp = malloc(size * count);
	if (temp == NULL)
		return (NULL);
	while (i < size * count)
		((unsigned char *)temp)[i++] = 0;
	return (temp);
}
