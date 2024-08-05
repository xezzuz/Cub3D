/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:15:49 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/05 10:39:13 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	end_index;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end_index = ft_strlen(s1);
	while (end_index && ft_strchr(set, s1[end_index - 1]))
		end_index--;
	result = (char *)malloc(((end_index + 1) * sizeof(char)));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, end_index);
	result[end_index] = '\0';
	return (result);
}
