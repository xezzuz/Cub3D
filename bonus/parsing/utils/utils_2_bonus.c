/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:04:06 by nazouz            #+#    #+#             */
/*   Updated: 2024/08/05 11:44:26 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				sign;
	long			result;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str < 14 && *str > 8))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str) || sign == -1)
		return (-1);
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str++ - 48);
		if (result > INT_MAX)
			return (-1);
	}
	if (!str_is_empty((char *)str))
		return (-1);
	return (result * sign);
}