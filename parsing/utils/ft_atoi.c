/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:04:06 by nazouz            #+#    #+#             */
/*   Updated: 2024/04/22 17:04:16 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_atoi(const char *str)
{
	int				sign;
	long			result;

	sign = 1;
	result = 0;
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
	if (*str)
		return (-1);
	return (result * sign);
}