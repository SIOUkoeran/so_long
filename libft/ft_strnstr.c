/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:34:20 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 22:08:08 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*str2 == '\0')
		return ((char *)str1);
	while (str1[i] != '\0' && i < len)
	{
		j = 0;
		while (str1[i + j] == str2[j] && str2[j] != '\0' && i + j < len)
			j++;
		if (str2[j] == '\0')
			return ((char *)&str1[i]);
		i++;
	}
	return (NULL);
}
