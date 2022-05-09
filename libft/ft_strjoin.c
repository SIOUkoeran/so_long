/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:10:47 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/09 19:35:44 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_length;
	char	*result_str;
    size_t	idx;

    idx = -1;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	result_str = malloc((total_length + 1) * sizeof(char));
	if (result_str == NULL)
		return (NULL);
    while (++idx < total_length + 1)
        result_str[idx] ='\0';
	if (result_str == NULL)
		return (NULL);
	ft_strlcat(result_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(result_str, s2, total_length + 1);
	free(s1);
	return (result_str);
}
