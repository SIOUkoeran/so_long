/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:43:42 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 22:01:13 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	idx;

	idx = 0;
	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s[idx] != '\0')
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	return (result);
}
