/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:19:53 by mkim3             #+#    #+#             */
/*   Updated: 2021/12/22 22:00:53 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char const *set, int c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		start;
	int		end;

	end = ft_strlen(s1) - 1;
	i = -1;
	start = 0;
	while (++i < ft_strlen(s1))
	{
		if (ft_is_in_set(set, s1[i]) == 1)
			start++;
		else if (ft_is_in_set(set, s1[i]) == 0)
			break ;
	}
	i = ft_strlen(s1);
	while (--i >= 0)
	{
		if (ft_is_in_set(set, s1[i]) == 1)
			end--;
		else if (ft_is_in_set(set, s1[i]) == 0)
			break ;
	}
	result = ft_substr(s1, (unsigned int) start, (size_t) end - start + 1);
	return (result);
}
