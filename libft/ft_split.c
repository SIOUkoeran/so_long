/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:01:59 by mkim3             #+#    #+#             */
/*   Updated: 2022/05/09 16:25:22 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_seperate(char c, char c1)
{
	if (c == c1)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

static int	ft_count(char const *str, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = -1;
	while (str[++i] != '\0')
		if (ft_seperate(str[i + 1], c) == 1)
			if (ft_seperate(str[i], c) == 0)
				cnt++;
	return (cnt);
}

static void	ft_print(char *des, char const *src, char c)
{
	int	i;

	i = -1;
	while (ft_seperate(src[++i], c) == 0)
		des[i] = src[i];
	des[i] = '\0';
}

static void	ft_print_split(char **split_str, char const *str, char c)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_seperate(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_seperate(str[i + j], c) == 0)
				j++;
			split_str[cnt] = (char *)malloc(sizeof(char) * (j + 1));
			ft_print(split_str[cnt], str + i, c);
			i += j;
			cnt++;
		}
	}
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		cnt;

	cnt = ft_count(str, c);
	result = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (result == NULL)
		return (NULL);
	result[cnt] = 0;
	ft_print_split(result, str, c);
	return (result);
}
