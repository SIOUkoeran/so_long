/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:11:24 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 22:03:44 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*result;
	size_t	result_size;

	length = ft_strlen(s);
	if (start >= length)
		return (ft_calloc(1, sizeof(char)));
	if (length - start <= len)
		len = length - start;
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	result_size = ft_strlcpy(result, s + start, len + 1);
	return (result);
}
