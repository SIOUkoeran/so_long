/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:43:59 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/09 19:24:32 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s1)
{
	size_t	length;
	
	length = 0;
	if (s1 == NULL)
		return (0);
    while (s1[length] != '\0')
		length++;
    return (length);
}
